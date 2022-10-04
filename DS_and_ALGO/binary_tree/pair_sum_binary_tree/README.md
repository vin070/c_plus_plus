**Pair Sum Binary Tree**

Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.

**Note**
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.

**INPUT FORMAT**\
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.\
The following line of input contains an integer, that denotes the value of S.

**OUTPUT FORMAT**\
Print each pair in a new line, as described in the task. 

**CONSTRAINTS**\
Time Limit: 1 second

**SAMPLE INPUT**
```
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
```

**SAMPLE OUTPUT**\
5 10\
6 9

**TIME COMPLEXITY**\
T(n) = O(nlog(n)) where n is number of nodes in tree

**SPACE COMPLEXITY**\
S(n) = O(n) where n is number of nodes in tree