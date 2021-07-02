#include<iostream>
#include<cmath>
int main()
{
    int baseSalary = 0 ,allowance = 0;
    char grade = NULL;
    
    std::cin>>baseSalary>>grade;
    
    if(grade == 'A')
      allowance = 1700;
    else if(grade == 'B')
      allowance = 1500;
    else
      allowance = 1300;
    
    long totalSalary = round((159.0 *baseSalary)/100 + allowance);
    
    std::cout<<totalSalary;
}