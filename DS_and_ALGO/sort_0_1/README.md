**You have been given an integer array/list(ARR) of size N that contains only integers, 0 and 1.\
Write a function to sort this array/list. Think of a solution which scans the array/list only once and don't require use of an extra array/list.** 

**NOTE** \
You need to change in the given array/list itself. Hence, no need to return or print anything. 

**INPUT FORMAT** \
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow. \
First line of each test case or query contains an integer 'N' representing the size of the array/list. \
Second line contains 'N' single space separated integers(all 0s and 1s) representing the elements in the array/list.

**OUTPUT FORMAT** \
For each test case, print the sorted array/list elements in a row separated by a single space. \
Output for every test case will be printed in a separate line.

**CONSTRAINTS** \
1 <= t <= 10^2 \
0 <= N <= 10^5 \
Time Limit: 1 sec

**SAMPLE INPUT 1** \
1 \
7 \
0 1 1 0 1 0 1

**SAMPLE OUTPUT 1** \
0 0 0 1 1 1 1 

**SAMPLE INPUT 2** \
2 \
8 \
1 0 1 1 0 1 0 1 \
5 \
0 1 0 1 0

**SAMPLE OUTPUT 2** \
0 0 0 1 1 1 1 1 \
0 0 0 1 1 

**TIME COMPLEXITY** \
O(n)