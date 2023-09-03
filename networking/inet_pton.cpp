#include <iostream>
#include <arpa/inet.h>// Required for inet_pton and inet_ntop method

int main() {
    auto const addr_family = AF_INET6;
    auto const add_len = INET6_ADDRSTRLEN;
    struct sockaddr_in6 a;
    //Convert address from plain text to network byte order
    inet_pton(addr_family, "2a03:2880:f144:82:face:b00c:0:25de", &a.sin6_addr);
    a.sin6_family = addr_family;
    a.sin6_port = htons(3000);

    char ip_addr[add_len];
    //Convert address from network byte order to plain text and store its result ip_addr variable
    auto result = inet_ntop(AF_INET6, &a.sin6_addr, ip_addr, add_len);
    if (result != nullptr) {
        std::cout << "ip address = " << ip_addr << '\n';
    }
    std::cout << "Port = " << ntohs(a.sin6_port) << '\n';
}