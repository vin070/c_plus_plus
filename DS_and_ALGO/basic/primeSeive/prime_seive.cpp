/*
   AIM = To find prime number using sieve of eratosthenes algorithm
   TIME COMPLEXITY = O(Nlog(logn))
*/

#include<iostream>
int main(){
     int n=0;
     std::cout<<"Enter a number to find all prime numbers below or less than or erqual to it"<<std::endl;
     std::cin>>n;
     bool numbers[n+1]={false};

     for(int i=2;i<n+1;i++)
     {
         // continue to next iteration when already checked
         if(numbers[i])
           continue;
         
         //break when square of number exceeds a given number
         if(i*i >n)
           break;

        for(int j=i*i;j<n+1;j++)
        {
            if(j%i == 0 && !numbers[j])
            numbers[j]=true;
        }
           
     }
     
     //print all the prime number
     for(int i=2;i<n+1;i++)
     {
         if(numbers[i]==false)
          std::cout<<i<<" ";
     }
      std::cout<<std::endl;     
      return 0;
}