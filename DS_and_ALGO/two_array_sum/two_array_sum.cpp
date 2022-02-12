#include <iostream>

void sum_of_two_array(int *input1, int size1, int *input2, int size2, int *output)
{
    int carry = 0;
    for(int input1_index = size1 -1, input2_index = size2 -1, output_index = size1 >= size2?size1 : size2;   
        output_index > 0;
        --input1_index, --input2_index, --output_index){
        
        int value_input1 = input1_index >= 0? input1[input1_index]: 0;
        int value_input2 = input2_index >= 0? input2[input2_index]: 0;
        
        output[output_index] = (carry + value_input1 + value_input2) % 10;
        carry = (carry + value_input1 + value_input2) / 10;
    }
    output[0] = carry;
}

int main()
{
	int t;
	std::cin >> t;

	while (t--){
		int size1;
		std::cin >> size1;

		int *input1 = new int[size1];

		for (int i = 0; i < size1; ++i)
			std::cin >> input1[i];

		int size2;
		std::cin >> size2;

		int *input2 = new int[size2];

		for (int i = 0; i < size2; ++i)
			std::cin >> input2[i];

		int outsize = 1 + std::max(size1, size2);

		int *output = new int[outsize];

		sum_of_two_array(input1, size1, input2, size2, output);

		for (int i = 0; i < outsize; ++i)
			std::cout << output[i] << " ";

		delete[] input1;
		delete[] input2;
		delete[] output;
		std::cout << std::endl;
	}

	return 0;
}