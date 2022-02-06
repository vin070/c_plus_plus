#include <iostream>
#include<climits>

int find_second_largest(int *input, int n){
    
    int largest = INT_MIN,
        second_largest = INT_MIN;   
    for(int i = 0; i < n; ++i){
        if(input[i] > largest){
            second_largest = largest;
            largest = input[i];
        }
        else if(input[i] > second_largest && input[i] < largest)
            second_largest = input[i];
    }
    return second_largest;
}

int main(){

	int t;
	std::cin >> t;
	while (t--){

		int size;
		std::cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; i++){
			std::cin >> input[i];
		}

		std::cout << find_second_largest(input, size) << std::endl;
		delete[] input;
	}
	return 0;
}