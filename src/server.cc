#include "muduo/base/Logging.h"
#include "muduo/net/EventLoop.h"
#include "muduo/net/InetAddress.h"
#include "muduo/net/TcpServer.h"

#include "openssl/ssl.h"
#include "openssl/err.h"
#include "openssl/ossl_typ.h"
#include "SSL_Util.h"
#include "com_protocol/mqtt/mqtt_protocol.h"


#include <utility>
#include <stdio.h>
#include <vector>
#include <functional>
#include <memory>
#include <string>
#include <iostream>


using namespace muduo;
using namespace muduo::net;

enum OVERLAPPED_TYPE
{
	RECV = 0,
	SEND = 1
};

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

class SSLServer : noncopyable {
private:
    std::map <TcpConnectionPtr, SSL_UtilPtr> m_connMap;
    TcpServer server_;
    unsigned long long  m_BytesSizeRecieved;

    bool m_Handshaked;
    unsigned long long  m_CurrRecived;
    unsigned long long  m_TotalRecived;
    std::vector<unsigned char> m_EncryptedSendData;
	std::vector<unsigned char> m_DecryptedRecvData;


public:
    SSLServer(EventLoop* loop,
        const InetAddress& serverAddr,
        const string& name
    ): server_(loop, serverAddr, name)
    {
        
        m_BytesSizeRecieved = 0;
        m_CurrRecived = 0;
        m_TotalRecived = 0;
        m_Handshaked = false;
        server_.setConnectionCallback(std::bind(&SSLServer::onServerConnection, this, _1));
		server_.setMessageCallback(std::bind(&SSLServer::onMessage, this, _1, _2, _3));
    }

    void start()
    {
        server_.start();
    }

    void stop()
    {
        loop_->queueInLoop(std::bind(&EventLoop::quit, loop_));
    }

private:
    void onServerConnection(const TcpConnectionPtr& conn)
    {
        if(conn->connected())
        {
            //std::shared_ptr<SSL_Util> ssl_util = std::make_shared<SSL_Util>(conn);
            //m_connMap[conn] = ssl_util;
            //ssl_util->set_receive_callback(std::bind(&SSLServer::handledata, this, _1, _2, _3));
            //ssl_util->SSL_Init();
            //ssl_util->SSL_Context_Creation();
        } else {
            //m_connMap.erase(conn);
			//LOG_WARN << "connect closed";
        }
    }

    void onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp timestamp)
    {
        //mqtt_protocol *mqtt = new mqtt_protocol();
		//mqtt->msg_init();

		//conn->send("nigelaji", 30);
        conn->send("receive connect", 30);

        /*from here you can see that the struct has to be packed*/
        
        /* original ssl server message*/
        //auto&  ssl_util = m_connMap[conn];
        //ssl_util->SSL_Recv_Data(conn, buf);
	    //buf->retrieveAll();
        //char szRequest[1024];
		//string html = "<h1>this message is from ssl server</h1>";
		//sprintf(szRequest,
		//	"HTTP/1.1 200 OK\r\n"
		//	"Content-Length: %d\r\n"
		//	"Connection: keep-alive\r\n"
		//	"\r\n"
		//	"%s",
		//	html.length(),
		//	html.c_str()
		//);
    }

public:
    int handledata( SSL_Util* ssl_conn, unsigned char* data, size_t datalen)
	{
		printf("handdledata, datalen:%d\n%s\n", datalen, data);

		char szRequest[1024];
		string html = "<h1>this message is from ssl server</h1>";
		sprintf(szRequest,
			"HTTP/1.1 200 OK\r\n"
			"Content-Length: %d\r\n"
			"Connection: keep-alive\r\n"
			"\r\n"
			"%s",
			html.length(),
			html.c_str()
		);
		string reqStr = string(szRequest);
		ssl_conn->SSL_Send_Request((char*)szRequest, reqStr.size());
		return 0;
	}

    void quit()
	{
		loop_->queueInLoop(std::bind(&EventLoop::quit, loop_));
	}


	EventLoop* loop_;


};

int main(int argc, char* argv[])
{
	Logger::setLogLevel(Logger::WARN);
	EventLoop loop;

	const char* ip = "127.0.0.1"; //"192.168.1.200";

	int16_t port = 1443;
	InetAddress listenAddr(ip, port);
	

	SSLServer server(&loop, listenAddr, "https server");
	server.start();

	loop.loop();
}