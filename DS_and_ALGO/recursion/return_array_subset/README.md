**Return subset of an array**

Given an integer array (of length n), find and return all the subsets of input array.\
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.\
Note : The order of subsets are not important.

**INPUT FORMAT**\
Line 1 : Size of array\
Line 2 : Array elements (separated by space)

**SAMPLE INPUT**\
3\
15 20 12

**SAMPLE OUTPUT**\
[] (this just represents an empty array, don't worry about the square brackets)\
12\
20\
20 12\ 
15\
15 12\
15 20\
15 20 12

**TIME COMPLEXITY**\
T(n) = O(2^n) where n is size of array.