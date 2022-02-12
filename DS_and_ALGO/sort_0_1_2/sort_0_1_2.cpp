#include <iostream>
#include <algorithm>

void swap_values(int *array, int i, int j){
     int temp = array[i];
     array[i] = array[j];
     array[j] = temp;
}

void sort012(int *input, int n){
    for(int next_zero = 0, next_two = n -1, i = 0; i <= next_two;){
        //Place zero to left side
        if(input[i] == 0){
            swap_values(input,i,next_zero);
            ++next_zero;
        }
        //Place 2 at right side
        else if( input[i] == 2){
            swap_values(input,i,next_two);
            --next_two;
        }
        
        if(input[i] == 1 && i >= next_zero)
            ++i;
        else if ( i < next_zero)
            i = next_zero;
    }
}
        
int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int size;
		std::cin >> size;
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
			std::cin >> arr[i];

		sort012(arr, size);

		for (int i = 0; i < size; i++)
			std::cout << arr[i] << " ";

		delete[] arr;
		std::cout << std::endl;
	}

	return 0;
}