#include <arpa/inet.h>
#include <error.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <vector>
#include <errno.h>
#include <iostream>
#include <unistd.h>

class SocketClient
{
private:
  int m_clientFd;
public:
  SocketClient(const int& sockfd) : m_clientFd(sockfd)
  {}
  int* GetClientSocketFd() { return &m_clientFd; }
};

class Address
{
private:
  sockaddr m_thisAddress;
  int m_port;

public:
  Address()
  {
    m_port = 5000;
    memset(&m_thisAddress, sizeof(sockaddr), 0x0);
  }

  static bool PopulateAddr(sockaddr* /*addr*/, const int& /*port*/);
  bool PopulateAddr()
  {
    return Address::PopulateAddr(&m_thisAddress, m_port);
  }

  bool PopulateAddr(const int& port)
  {
    m_port = port;
    return PopulateAddr();
  }

  sockaddr* GetAddr()
  {
    return &m_thisAddress;
  }
};

bool Address::PopulateAddr(sockaddr* addr, const int& port)
{
  sockaddr_in* pSockAddr_in = reinterpret_cast<sockaddr_in*>(addr);
  memset(pSockAddr_in, sizeof(sockaddr_in), 0x0);
  pSockAddr_in->sin_family = AF_INET;
  pSockAddr_in->sin_port = htonl(port);
  pSockAddr_in->sin_addr.s_addr = INADDR_ANY;
  return true;
}
enum ServerType
{
  TCP,
  UDP
};
class Server
{

  // current socket
  int m_ServerSocketFd;
  Address m_ServerAddress;
  ServerType m_ServerType;

public:
  Server(const int& port)
  {
    m_ServerSocketFd = -1;
    m_ServerAddress.PopulateAddr(port);
  }

  bool CloseSocket()
  {
    
    if (isSocketInvalid())
    {
      return false;
    }
    close(m_ServerSocketFd);
    return true;
  }


  bool CreateSocket()
  {
    if (!m_ServerAddress.PopulateAddr(5000))
    {
      perror("Cant get address");
      return false;
    }

    m_ServerSocketFd = socket(PF_INET, SOCK_STREAM, 0);
    return true;
  }

  bool isSocketInvalid()
  {
    return m_ServerSocketFd <= 0 ? true : false;
  }

  bool startListnening()
  {
    if (isSocketInvalid())
      return false;

    int yes = 1;
    setsockopt(m_ServerSocketFd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

    int errNo = 0;
    if (!(errNo = bind(m_ServerSocketFd, m_ServerAddress.GetAddr(), sizeof(*m_ServerAddress.GetAddr()))))
    {
      perror("Cant bind to address");
      return false;
    }

    if (!listen(m_ServerSocketFd, 1))
    {
      perror("Unable to listen");
      return false;
    }

    return true;
  }
};

int main(int argc, char const* argv[])
{
  Server s1(5000);
  if (s1.CreateSocket())
  {
    if (!s1.startListnening())
    {
      std::cout << "Unable to listen "<< errno << "\n";

    }
  }

  return 0;
}
