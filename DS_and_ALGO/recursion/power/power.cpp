#include<iostream>

unsigned long power(int x, int n) {
    if(n == 0)
        return 1;
    
    return x * power(x, n-1); 
}
int main(){
    int x = 0, n = 0;
    std::cin >> x >> n;
    std::cout << power(x, n) << '\n';
}

//TODO: store large numbers in case of factorial problem.