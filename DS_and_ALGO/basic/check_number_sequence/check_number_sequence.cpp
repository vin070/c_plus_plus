#include<iostream>
#include<climits>

int main(){
    int n=0,
        currnet_n=INT_MAX,
        previous_n = INT_MAX;
    bool is_decreasing = true;

    std::cin>>n;

    for(int i = 0; i < n; i++){
        previous_n = currnet_n;
        std::cin>>currnet_n;

        if((!is_decreasing && currnet_n < previous_n) 
           || (currnet_n == previous_n))
               break;
        else if(is_decreasing && currnet_n >previous_n)
                is_decreasing = false;    
    }

    if((is_decreasing && currnet_n < previous_n)
      || (!is_decreasing && currnet_n > previous_n))
        std::cout<<"true";
    else 
        std::cout<<"false";
}