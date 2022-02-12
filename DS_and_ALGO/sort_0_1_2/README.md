**Sort 0 1 2**\

**You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list in a 'single scan'. \
'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once. **\

**NOTE** \
You need to change in the given array/list itself. Hence, no need to return or print anything. 

**INPUT FORMAT** \
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow. \
First line of each test case or query contains an integer 'N' representing the size of the array/list.\
Second line contains 'N' single space separated integers(all 0s, 1s and 2s) representing the elements in the array/list.

**OUTPUT FORMAT**\
For each test case, print the sorted array/list elements in a row separated by a single space.\
Output for every test case will be printed in a separate line.

**CONSTRAINTS** \
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec

**SAMPLE INPUT1** \
2\
5\
2 2 0 1 1\
7\
0 1 2 0 1 2 0

**SAMPLE OUTPUT1**\
0 1 1 2 2\
0 0 0 1 1 2 2

**TIME COMPLEXITY** \
O(n)