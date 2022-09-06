**BST to sorted linked list**

Given a BST, convert it into a sorted linked list. You have to return the head of linked list.

**INPUT FORMAT**\
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

**OUTPUT FORMAT**\
The first and only line of output prints the elements of sorted linked list.

**CONSTRAINTS**\
Time Limit: 1 second

**SAMPLE INPUT**
```
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
```

**SAMPLE OUTPUT**\
2 5 6 7 8 10

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of nodes in tree

**SPACE COMPLEXITY**\
S(n) = O(n) where n is number of nodes in tree