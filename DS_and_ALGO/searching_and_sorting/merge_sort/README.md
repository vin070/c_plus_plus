**Merge Sort Code**

Sort an array A using Merge Sort.\
Change in the input array itself. So no need to return or print anything.

**INPUT FORMAT**\
Line 1 : Integer n i.e. Array size\
Line 2 : Array elements (separated by space)

**OUPUT FORMAT**\
Array elements in increasing order (separated by space)

**CONSTRAINTS**\
1 <= n <= 10^3

**SAMPLE INPUT**\
6\
2 6 8 5 4 3

**SAMPLE OUPUT**\
2 3 4 5 6 8

**TIME COMPLEXITY**\
O(nlog(n)) where n is length of array.\
Equation for finding time complexity is T(n) = 2T(n/2) + n