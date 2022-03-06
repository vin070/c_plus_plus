**Leaders in array**\

Given an integer array A of size n. Find and print all the leaders present in the input array. An array element A[i] is called Leader, if all the elements following it (i.e. present at its right) are less than or equal to A[i].\
Print all the leader elements separated by space and in the same order they are present in the input array.

**INPUT FORMAT**\
Line 1 : Integer n, size of array\
Line 2 : Array A elements (separated by space)

**OUTPUT FORMAT**\
leaders of array (separated by space)

**CONSTRAINTS**\
1 <= n <= 10^6

**SAMPLE INPUT 1**\
6\
3 12 34 2 0 -1

**SAMPLE OUTPUT 1**\
34 2 0 -1

**TIME COMPLEXITY**\
O(n) where n is length of array