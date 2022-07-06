#include<iostream>

int last_index(int input[], int size, int x) {
  if( size == 0)
      return -1;
  else if(input[size - 1] == x)
      return size - 1;
   
  return last_index(input, size - 1, x);
}


int main(){
    int n = 0,
        x = 0;
    std::cin >> n;
  
    int *input = new int[n]; 
    for(int i = 0; i < n; i++)
        std::cin >> input[i];
    
    std::cin >> x;
    
    std::cout << last_index(input, n, x) << '\n';
    delete [] input;

}


