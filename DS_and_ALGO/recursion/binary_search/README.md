**Binary Search (Recursive)**

Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search.\ Return the index of x.\
Return -1 if x is not present in the given array.\
Note : If given array size is even, take first mid.

**INPUT FORMAT**\
Line 1 : Array size\
Line 2 : Array elements (separated by space)\
Line 3 : x (element to be searched)\

**SAMPLE INPUT**\
6\
2 3 4 5 6 8\
5

**SAMPLE OUTPUT**\
3

**TIME COMPLEXITY**\
T(n) = O(log2n) where n is size of array.