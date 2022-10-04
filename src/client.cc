#include <muduo/net/Channel.h>
#include <muduo/net/TcpClient.h>
 
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>

#include "com_protocol/mqtt/mqtt_protocol.h"
 
#include <stdio.h>
 
using namespace muduo;
using namespace muduo::net;
 
class TestClient
{
 public:
  TestClient(EventLoop* loop, const InetAddress& listenAddr)
    : loop_(loop),
      client_(loop, listenAddr, "TestClient"),
	  //标准输入通道对应的文件描述符是0
      stdinChannel_(loop, 0)
  {
    client_.setConnectionCallback(
        std::bind(&TestClient::onConnection, this, std::placeholders::_1));
    client_.setMessageCallback(
        std::bind(&TestClient::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	//连接已经建立成功，由于某种原因断开而进行的重连
    //client_.enableRetry();
    // 标准输入缓冲区中有数据的时候，回调TestClient::handleRead
    stdinChannel_.setReadCallback(std::bind(&TestClient::handleRead, this));
	stdinChannel_.enableReading();		// 关注可读事件
  }
 
  void connect()
  {
    client_.connect();
  }
 
 private:
  void onConnection(const TcpConnectionPtr& conn)
  {
    if (conn->connected())
    {
      mqtt_connect_info_t info = {
        .client_id = "nibaba",
        .username = "user",
        .password = "password",
        .will_topic = "willtopic",
        .will_message = "willmessage",
        .keepalive = 23,
      };
      mqtt_protocol *mqtt = new mqtt_protocol();
		  mqtt->msg_init();
      mqtt->mqtt_msg_connect(&info);
      printf("onConnection(): new connection [%s] from %s\n",
             conn->name().c_str(),
             conn->peerAddress().toIpPort().c_str());
      conn->send(mqtt->get_message(), 512);
    }
    else
    {
      printf("onConnection(): connection [%s] is down\n",
             conn->name().c_str());
    }
  }
 
  void onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp time)
  {
    string msg(buf->retrieveAllAsString());
    printf("onMessage(): recv a message [%s]\n", msg.c_str());
    LOG_TRACE << conn->name() << " recv " << msg.size() << " bytes at " << time.toFormattedString();
  }
 
  // 标准输入缓冲区中有数据的时候，回调该函数
  void handleRead()
  {
    char buf[1024] = {0};
    fgets(buf, 1024, stdin);
	buf[strlen(buf)-1] = '\0';		// 去除\n
	client_.connection()->send(buf);
  }
 
  EventLoop* loop_;
  TcpClient client_;
  Channel stdinChannel_;		// 标准输入Channel
};
 
int main(int argc, char* argv[])
{
  LOG_INFO << "pid = " << getpid() << ", tid = " << CurrentThread::tid();
  EventLoop loop;
  InetAddress serverAddr("127.0.0.1", 1443);
  TestClient client(&loop, serverAddr);
  client.connect();
  loop.loop();
}
