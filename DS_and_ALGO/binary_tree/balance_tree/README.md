**Check Balanced**

Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.\
Balanced Binary Tree:\
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:\
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    

**INPUT FORMAT**\
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

**OUTPUT FORAMT**\
The first and only line of output contains true or false.

**CONSTRAINTS**\
Time Limit: 1 second

**SAMPLE INPUT 1**
```
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
```

**SAMPLE OUTPUT 1**\
false

**SAMPLE INPUT 1**
```
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
```

**SAMPLE OUTPUT 1**\
false

**TIME COMPLEXITY**\
T(n) = O(n) where n number of node in tree

**SPACE COMPLEXITY**\
s(n) = O(h) where h is height of tree