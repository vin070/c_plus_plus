**Check if a Binary Tree is BST**

Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.

**NOTE**\
Duplicate elements should be kept in the right subtree.

**INPUT FORMAT**\
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

**OUTPUT FORMAT**\
The first and only line of output contains either true or false.

**CONSTRAINTS**\
Time Limit: 1 second

**SAMPLE INPUT**
```
5 1 6 -1 -1 8 7 -1 -1 -1 -1
```

**SAMPLE OUTPUT**\
false

**TIME COMPLEXITY**\
T(n) = O(n) where n number of node in tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of tree
