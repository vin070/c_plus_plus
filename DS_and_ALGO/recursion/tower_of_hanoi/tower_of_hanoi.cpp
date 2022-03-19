#include <iostream>

void tower_of_hanoi(int const n, char const &source, char const &auxiliary, char const &destination) {
    if(n == 1){
        std::cout<<source<<" "<<destination<<'\n';
        return;
    }
    else if (n <= 0)
        return;
        
    tower_of_hanoi(n - 1, source, destination, auxiliary);
    std::cout<<source<<" "<<destination<<'\n';
    tower_of_hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n = 0;
    std::cin >> n;
    tower_of_hanoi(n, 'a', 'b', 'c');
}