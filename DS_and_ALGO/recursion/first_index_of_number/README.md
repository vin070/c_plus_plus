**First Index of Number**

Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.\
First index means, the index of first occurrence of x in the input array.\
Do this recursively. Indexing in the array starts from 0.

**INPUT FORMAT**\
Line 1 : An Integer N i.e. size of array\
Line 2 : N integers which are elements of the array, separated by spaces\
Line 3 : Integer x

**OUTPUT FORMAT**\
first index or -1

**CONSTRAINTS**\
1 <= N <= 10^3

**SAMPLE INPUT**\
4\
9 8 10 8\
8

**SAMPLE OUTPUT**\
1

**TIME COMPLEXITY**\
O(n) where n is length of array