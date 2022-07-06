**You have been given a sorted(in ascending order) integer array/list(ARR) of size N and an element X. Write a function to search this element in the given input array/list using 'Binary Search'. \ Return the index of the element in the input array/list. In case the element is not present in the array/list, then return -1.**

**INPUT FORMAT** \
The first line contains an Integer 'N' which denotes the size of the array/list. \
Second line contains 'N' single space separated integers representing the elements in the array/list. \
Third line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow. \
All the 't' lines henceforth, will take the value of X to be searched for in the array/list.

**OUTPUT FORMAT** \
For each test case, print the index at which X is present, -1 otherwise \.
Output for every test case will be printed in a separate line.

**CONSTRAINTS** \
1 <= t <= 10^4 \
0 <= N <= 10^6 \
0 <= X <= 10^9

**TIME LIMIT** \
1 sec

**SAMPLE INPUT 1** \
7 \
1 3 7 9 11 12 45 \
1 \
3

**SAMPLE OUTPUT 1** \
1

**SAMPLE INPUT 2** \
7 \
1 2 3 4 5 6 7 \
2 \
9 \
7

**SAMPLE OUTPUT 2** \
-1 \ 
6

**TIME COMPLEXITY** \
O(log2(n))