#include<iostream>

/**
 * @param { int } farenheiht_start - Starting value of farenheit 
 * @param { int } farenheit_end - End value of farenheit to which conversions will take place
 * @param { int } step_size  
 * @returns { void }
*/
void farenheit_to_celsius(int farenheit_start, int farenheit_end, int step_size) {
    
    for(;farenheit_start < farenheit_end; farenheit_start  += step_size)
        std::cout<<farenheit_start<<"\t"<<((farenheit_start - 32)*5)/9<<'\n';
}

int main(){

    int farenheit_start = 0,
        farenheit_end = 0,
        step_size = 0;

    std::cout<<"Enter farenheit starting value"<<"\n";
    std::cin>>farenheit_start;

    std::cout<<"Enter farenheit ending value"<<"\n";
    std::cin>>farenheit_end;

    std::cout<<"Enter step size"<<"\n";
    std::cin>>step_size;
    
    farenheit_to_celsius(farenheit_start, farenheit_end, step_size);
    
}


