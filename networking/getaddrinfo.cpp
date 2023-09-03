#include<iostream>
#include<cstring>
#include <netdb.h>
#include<arpa/inet.h>
#include<sys/types.h>

auto find_ip_address(const char* domain, const char* service) {
  addrinfo hints, * res;
  std::memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  int const status = getaddrinfo(domain, service, &hints, &res);
  if (status != 0) {
    std::cerr << "getaddrinfo error: " << gai_strerror(status) << std::endl;
    res = nullptr;
  }
  return res;
}

int main() {
  std::string domain;
  std::string protocol;
  std::cin >> domain >> protocol;
  auto ans = find_ip_address(domain.c_str(), protocol.c_str());
  for (auto res = ans; res != nullptr; res = res->ai_next) {
    int addr_len;
    void* addr;
    std::string type;
    if (res->ai_family == AF_INET) {
      addr_len = INET_ADDRSTRLEN;
      type = "IPV4";
      sockaddr_in* ipv4_addr = (sockaddr_in*)res->ai_addr;
      addr = &ipv4_addr->sin_addr;
    }
    else if (res->ai_family == AF_INET6) {
      addr_len = INET6_ADDRSTRLEN;
      type = "IPV6";
      auto ipv6_addr = (sockaddr_in6*)res->ai_addr;
      addr = &ipv6_addr->sin6_addr;
    }
    char ip_addr[addr_len];
    inet_ntop(res->ai_family, addr, ip_addr, addr_len);
    std::cout << type << " = " << ip_addr << '\n';
  }
  freeaddrinfo(ans);
}