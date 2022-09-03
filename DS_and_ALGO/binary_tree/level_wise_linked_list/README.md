**Level wise linkedlist**

Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.

**INPUT FORMAT**\
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

**OUTPUT FORMAT**\
Each level linked list is printed in new line (elements are separated by space).

**CONSTRAINTS**\
Time Limit: 1 second

**SAMPLE INPUT**
```
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
```

**SAMPLE INPUT** 
5\
10 6\
2 3\
9

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of nodes in tree

**SPACE COMPLEXITY**\
S(n) = O(2<sup>l</sup>) where l is largest level in tree 