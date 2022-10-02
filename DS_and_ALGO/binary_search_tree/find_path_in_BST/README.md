**Find Path in BST**

Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.

**NOTE**: Assume that BST contains all unique elements.

**INPUT FORMAT**\
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.\
The following line of input contains an integer, that denotes the value of k.

**OUTPUT FORMAT**\
The first line and only line of output prints the data of the nodes in the path from node k to root. The data of the nodes is separated by single space.


**CONSTRAINTS**\
Time Limit: 1 second

**SAMPLE INPUT**
```
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
```

**SAMPLE OUTPUT**\
2 5 8

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of node in tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of tree or length of output array.