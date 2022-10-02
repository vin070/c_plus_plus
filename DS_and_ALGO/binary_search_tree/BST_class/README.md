**Code: BST Class**

Implement the BST class which includes following functions -
1. insert \
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
2. search\
Given an element, find if that is present in BST or not. Return true or false.
3. delete\
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive)\
Print the BST in in the following format -
For printing a node with data N, you need to follow the exact format\
N:L:x,R:y\
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.

**SAMPLE INPUT**
```
6
1 2
1 3
1 1
4
2 2
4
```

**SAMPLE OUTPUT**\
2:L:1,R:3\
1:\
3:\
3:L:1,\
1: