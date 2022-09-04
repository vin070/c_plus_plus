**Nodes without sibling**

For a given Binary Tree of type integer, print all the nodes without any siblings.

**INPUT FORMAT**\
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

**OUTPUT FORMAT**\
The only line of output prints the node data in a top to down fashion with reference to the root.\
Node data in the left subtree will be printed first and then the right subtree.\
A single space will separate them all.

**CONSTRAINTS**\
1 <= N <= 10<sup>5</sup>\
Where N is the total number of nodes in the binary tree.\
Time Limit: 1 second

**SAMPLE INPUT**
```
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
```

**SAMPLE OUTPUT**\
9

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of nodes in tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of tree