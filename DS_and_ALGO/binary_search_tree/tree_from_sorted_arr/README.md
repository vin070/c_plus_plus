**Construct BST from a Sorted Array**

Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.

**NOTE**\
If array size is even, take first mid as root.

**INPUT FORMAT**\
The first line of input contains an integer, which denotes the value of n. The following line contains n space separated integers, that denote the values of array.

**OUTPUT FORMAT**\
The first and only line of output contains values of BST nodes, printed in pre order traversal.

**CONSTRAINTS**\
Time Limit: 1 second

**SAMPLE INPUT**
```
7
1 2 3 4 5 6 7
```

**SAMPLE OUTPUT**\
4 2 1 3 6 5 7 

**TIME COMPLEXITY**\
T(n) = O(n) where n is length of array

**SPACE COMPLEXITY**\
S(n) = O(n) where n is length of array