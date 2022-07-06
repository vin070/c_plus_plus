#include <iostream>

int max_money_looted(int * const array, int const &n) { 
    if( n <= 0)
        return 0;
    else if(n == 1)
        return array[0];
    else if( n == 2)
        return array[0] >= array[1]? array[0]:array[1];

    for(int i = 2; i < n; ++i) { 
        if(array[i] + array[i - 2] > array[i - 1]) 
            array[i] += array[i - 2];
        else
            array[i] = array[i - 1];
    }
    return array[n - 1];
}

int main() {
	int n = 0;
	std::cin >> n;
	int *array = new int[n];
	for (int i = 0; i < n; ++i)
		std::cin >> array[i];

	std::cout << max_money_loooted_recursive(array,n);
	delete[] array;
}