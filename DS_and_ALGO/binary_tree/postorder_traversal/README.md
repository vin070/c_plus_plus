**Postorder Binary Tree**

For a given Binary Tree of integers, print the post-order traversal.

**INPUT FORMAT**\
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

**OUTPUT FORMAT**\
The only line of output prints the post-order traversal of the given binary tree.

**CONSTRAINTS**\
1 <= N <= 10<sup>6</sup>\
Where N is the total number of nodes in the binary tree.\
Time Limit: 1 sec

**SAMPLE INPUT**
```
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
```

**SAMPLE OUTPUT**\
4 5 2 6 7 3 1 

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of node in binary tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of binary tree