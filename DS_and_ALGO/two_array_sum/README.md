**Sum of Two Arrays**\
Two random integer arrays/lists have been given as ARR1 and ARR2 of size N and M respectively. Both the arrays/lists contain numbers from 0 to 9(i.e. single digit integer is present at every index). The idea here is to represent each array/list as an integer in itself of digits N and M. \
You need to find the sum of both the input arrays/list treating them as two integers and put the result in another array/list i.e. output array/list will also contain only single digit at every index.

**NOTE** \
The sizes N and M can be different. \
Output array/list(of all 0s) has been provided as a function argument. Its size will always be one more than the size of the bigger array/list. Place 0 at the 0th index if there is no carry. \
No need to print the elements of the output array/list. \
Using the function "sum_of_two_array", write the solution to the problem and store the answer inside this output array/list. The main code will handle the printing of the output on its own.

**INPUT FORMAT** \
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.\
First line of each test case or query contains an integer 'N' representing the size of the first array/list.\
Second line contains 'N' single space separated integers representing the elements of the first array/list. \
Third line contains an integer 'M' representing the size of the second array/list.\
Fourth line contains 'M' single space separated integers representing the elements of the second array/list.

**OUTPUT FORMAT**\
For each test case, print the required sum of the arrays/list in a row, separated by a single space.\
Output for every test case will be printed in a separate line.

**CONSTRAINTS**\
1 <= t <= 10^2\
0 <= N <= 10^5\
0 <= M <= 10^5\
Time Limit: 1 sec\

**SAMPLE INPUT1**\
1\
3\
6 2 4\
3\
7 5 6

**SAMPLE OUTPUT1**\
1 3 8 0
