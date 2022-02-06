**You have been given a random integer array/list(ARR) of size N. You are required to find and return the second largest element present in the array/list.\
If N <= 1 or all the elements are same in the array/list then return -2147483648 or -2^31(It is the smallest value for the range of Integer)**

**INPUT FORMAT**\
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.\
The first line of each test case or query contains an integer 'N' representing the size of the array/list.\
The second line contains 'N' single space separated integers representing the elements in the array/list.

**OUTPUT FORMAT**\
For each test case, print the second largest in the array/list if exists, -2147483648 otherwise.\
Output for every test case will be printed in a separate line.

**CONSTRAINTS**\
1 <= t <= 10^2\
0 <= N <= 10^5\
Time Limit: 1 sec

**SAMPLE OUTPUT 1**\
1
7
2 13 4 1 3 6 28

**SAMPLE OUTPUT 1**\
13

**SAMPLE OUTPUT 2**\
2
2
6 6
4
90 8 90 5

**SAMPLE OUTPUT 2**\
-2147483648
8

**TIME COMPLEXITY** \
O(n)