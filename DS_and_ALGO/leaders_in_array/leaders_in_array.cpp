#include<iostream>
#include<climits>

void leaders(int const* const arr, int const len) {
    int *leaders = new int[len]{0},
	     leader = INT_MIN;
    
    //Find leaders in array and store it.
	for(int i = len - 1; i >= 0; --i) {
		if(arr[i] >= leader) {
            leader = arr[i];
			leaders[i] = len - i;   
		}
	}
    
    //Print the leaders
	for(int i = 0; i < len; ++i) {
		if(leaders[i] != 0)
		    std::cout<<arr[i]<<" ";
	}

	delete [] leaders;
}

int main() {

    int len = 0;
    std::cin>>len;
	int *arr = new int[len + 1];	
	for(int i = 0; i < len; ++i)
		std::cin>>arr[i];
	
	leaders(arr,len);
	delete [] arr;
}
