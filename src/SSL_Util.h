#include "muduo/base/Logging.h"
#include "muduo/net/TcpConnection.h"
#include "muduo/net/TcpServer.h"

#include <iostream>
#include <vector>
#include <functional>
#include "openssl/ssl.h"
#include "openssl/err.h"
#include "openssl/ossl_typ.h"

void handle_error()
{
    std::cout << "Error occured!" << std::endl;

}

class SSL_Util {
private:
    muduo::net::TcpConnectionPtr conn_;
    SSL_CTX *ssl_ctx;
    SSL* ssl;
    BIO *Bio_buf[2];
    std::vector<unsigned char> EncryptedSendData;
    std::vector<unsigned char> DecryptedSendData;
    unsigned long long  m_CurrRecived;
    unsigned long long m_TotalRecived;
    unsigned long long  m_BytesSizeRecieved;
    bool ssl_Handshaked;

    std::function<int(SSL_Util*, unsigned char*, size_t)> SSL_receive_callback;
    
    void SSL_close_session() {
        printf("close_session()\n");
        conn_->forceClose();
    }

    void SSLRequestReply()
    {
        printf("m_CurrRecived:%d ", m_CurrRecived);
        printf("m_TotalRecived:%d\n ", m_TotalRecived);

        if(SSL_receive_callback)
        {
            SSL_receive_callback(this, DecryptedSendData.data(), DecryptedSendData.size());
        }

        DecryptedSendData.clear();
    }

    void SSL_Set_Certificate() {
        BIO *in_file;

        in_file = BIO_new(BIO_s_file());
        if(in_file == NULL) {
            std::cout << "BIO object creation failed!\n" << std::endl;
            SSL_close_session();
        }

        if(BIO_read_filename(in_file, "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/src/server.pem") <= 0) {
            printf("BIO file read failed!\n");
            SSL_close_session();
        }

        X509 *cert = PEM_read_bio_X509(in_file, nullptr, nullptr, nullptr);
        EVP_PKEY *pkey = PEM_read_bio_PrivateKey(in_file, 0, 0, 0);

        int ret = SSL_CTX_use_certificate(ssl_ctx, cert);

        if (ret != 1)
			SSL_close_session();

        ret = SSL_CTX_use_PrivateKey(ssl_ctx, pkey);

		if (ret != 1)
			SSL_close_session();

        if(ret != 1)
        {
            printf("Private key read failed!\n");
            SSL_close_session();
        }

        X509_free(cert);
        EVP_PKEY_free(pkey);
        BIO_free(in_file);
    }

    bool IsSSLError(int ssl_error)
	{
		switch (ssl_error)
		{
		case SSL_ERROR_NONE:
		case SSL_ERROR_WANT_READ:
		case SSL_ERROR_WANT_WRITE:
		case SSL_ERROR_WANT_CONNECT:
		case SSL_ERROR_WANT_ACCEPT:
			return false;

		default: return true;
		}
	}

public:
    SSL_Util(const muduo::net::TcpConnectionPtr& conn);
    ~SSL_Util();
    void set_receive_callback(std::function<int(SSL_Util*, unsigned char*, size_t)> fun) { SSL_receive_callback = fun; }
    void SSL_Init();
    void SSL_Context_Creation();
    void SSL_Send_Data();
    void SSL_Send_Request(char* data, size_t size);
    void SSL_Recv_Data(const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf);
};

void SSL_Util::SSL_Send_Request(char* data, size_t size)
{
    int	ret = SSL_write(ssl, data, size);
	int	ssl_error = SSL_get_error(ssl, ret);

	if (IsSSLError(ssl_error))
		SSL_close_session();
	printf("process send 1 \n");
    SSL_Send_Data();
}

SSL_Util::SSL_Util(const muduo::net::TcpConnectionPtr& conn)
{
    m_CurrRecived = 0;
	m_BytesSizeRecieved = 0;
	m_TotalRecived = 0;
    ssl_Handshaked = false;
    EncryptedSendData.resize(1024 * 10);
    DecryptedSendData.resize(1024 * 10);
    conn_ = conn;
}

void SSL_Util::SSL_Init()
{
    SSL_load_error_strings();
    SSL_library_init();

    OpenSSL_add_all_algorithms();
    ERR_load_BIO_strings();
}

SSL_Util::~SSL_Util()
{
    printf("~SSL_Util()\n");
    if(ssl)
    {
        SSL_free(ssl);
    }

    if(ssl_ctx)
    {
        SSL_CTX_free(ssl_ctx);
    }
}

void SSL_Util::SSL_Context_Creation()
{
    ssl_ctx = SSL_CTX_new(SSLv23_server_method());
    SSL_CTX_set_verify(ssl_ctx, SSL_VERIFY_NONE, nullptr);
    SSL_Set_Certificate();
    ssl = SSL_new(ssl_ctx);
    Bio_buf[1] = BIO_new(BIO_s_mem());
    Bio_buf[0] = BIO_new(BIO_s_mem());
    SSL_set_bio(ssl, Bio_buf[0], Bio_buf[1]);
    SSL_set_accept_state(ssl);
}

void SSL_Util::SSL_Send_Data()
{
    int ret;
    int ssl_error;

    while(BIO_pending(Bio_buf[1]))
    {
        ret = BIO_read(Bio_buf[1], EncryptedSendData.data(), EncryptedSendData.size());
        if(ret > 0)
        {
            printf("process send:%s\n", EncryptedSendData.data());
			conn_->send(reinterpret_cast<char*>(EncryptedSendData.data()), ret);
        } else {
            printf("process send failed!");
			ssl_error = SSL_get_error(ssl, ret);

			if (IsSSLError(ssl_error))
			    SSL_close_session();
        }
    }
}

void SSL_Util::SSL_Recv_Data(const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf)
{
    printf("receive data, size:%d \n", buf->readableBytes());
    int ret;
	int ssl_error;
    
    auto datalen = buf->readableBytes();
	m_BytesSizeRecieved += datalen;

    if (m_BytesSizeRecieved > 0)
	{
        std::cout << "data received!" << std::endl;
		ret = BIO_write(Bio_buf[0], buf->peek(), datalen);

		if (ret > 0)
		{
			int intRet = ret;
			if (intRet > m_BytesSizeRecieved)
				SSL_close_session();

			m_BytesSizeRecieved -= intRet;
		}else{
            std::cout << "data Decrypted error 2!" << std::endl;
			ssl_error = SSL_get_error(ssl, ret);
			if (IsSSLError(ssl_error))
				SSL_close_session();
		}
	}

    do
		{
            std::cout << "data encrypted!" << std::endl;
			ret = SSL_read(ssl, DecryptedSendData.data() + m_CurrRecived, DecryptedSendData.size() - m_CurrRecived);
            std::cout << "data encrypted error!" << ret << std::endl;
			if (ret > 0)
			{
				m_CurrRecived += ret;
		    	m_TotalRecived += ret;

                if(ssl_Handshaked)
                {
                    SSLRequestReply();
                }    
			}
			else
			{
               std::cout << "data Decrypted error 1!" << std::endl;
				ssl_error = SSL_get_error(ssl, ret);

				if (IsSSLError(ssl_error))
                {
                    std::cout << "data Decrypted error!" << std::endl;
                    SSL_close_session();
                }			
			}
		} while (ret > 0);

        if(!ssl_Handshaked)
        {
            printf("bonbonbon \n");
            if(SSL_is_init_finished(ssl))
            {
                printf("Hand shake finish \n");
			    ssl_Handshaked = true;
            }
        }
    
    printf("process send 2 \n");
    SSL_Send_Data();

}

typedef std::shared_ptr<SSL_Util> SSL_UtilPtr;

