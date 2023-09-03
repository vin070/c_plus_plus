
/**
#include <random>
#include <thread>
#include <utility>
#include <unistd.h>
#include <cerrno>
#include <functional>
#include <map>
#include <sstream>
#include <stdexcept>
#include <sys/time.h>
#include <chrono>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <string>
#include <type_traits>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/resource.h>
*/
/* IC221 Spring 2019
 * Lab 11: Network Addressing
 * YOUR NAME HERE
 */

#include <iostream>
#include<cstring>
#include<sys/socket.h>
#include <sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
#include <stdlib.h>     /* getenv */
using namespace std;

struct mystruct {
  int i;
  int j;
  char m;
  bool n;
};

int main(int  argc, char** argv, char** envp) {
  for (char** env = envp; *env != 0; env++)
  {
    char* thisEnv = *env;
    std::cout << thisEnv << '\n';
  }

  char* pPath;
  putenv("Hi=VIneet");
  pPath = getenv("Hi");
  std::cout<<"I am the boss "<<pPath<<"\n";
  

  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    std::cout << "Error creating socket";
    return 1;
  }
  sockaddr_in addr;
  std::memset(&addr, 0, sizeof(addr));

  addr.sin_family = AF_INET;
  inet_pton(AF_INET, "0.0.0.0", &addr.sin_addr);
  addr.sin_port = htons(3000);
  bind(socket_fd, (sockaddr*)&addr, sizeof(addr));

  if (listen(socket_fd, 2) == -1) {
    std::cout << "Error listenin";
  }

  while (true) {
    sockaddr_storage client_addr;
    socklen_t  client_addr_len = sizeof(client_addr);
    int client_fd = accept(socket_fd, reinterpret_cast<sockaddr*>(&client_addr), &client_addr_len);
    if (client_fd == -1) {
      std::cout << "Error accepting client rerquest";
      continue;
    }

    char client_ip[INET6_ADDRSTRLEN];
    if (client_addr.ss_family == AF_INET) {
      sockaddr_in* client = reinterpret_cast<sockaddr_in*>(&client_addr);
      inet_ntop(AF_INET, &(client->sin_addr), client_ip, INET_ADDRSTRLEN);
    }
    else if (client_addr.ss_family == AF_INET6) {
      sockaddr_in6* client = reinterpret_cast<sockaddr_in6*>(&client_addr);
      inet_ntop(AF_INET, &(client->sin6_addr), client_ip, INET6_ADDRSTRLEN);
    }
    char buffer[1024];
    ssize_t bytesRead = read(client_fd, buffer, sizeof(buffer) - 1);
    std::cout << buffer << '\n';
    std::cout << "client IP = " << client_ip << '\n';
    close(client_fd);
  }

  close(socket_fd);
}
