**Print tree in zigzag faishon**

Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.

**INPUT FORMAT**
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

**OUTPUT FORMAT**\
The binary tree is printed level wise, as described in the task. Each level is printed in new line.

**CONSTRAINTS**\
Time Limit: 1 second

**SAMPLE INPUT**
```
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
```

**SAMPLE OUTPUT**
5\
10 6\
2 3\
9