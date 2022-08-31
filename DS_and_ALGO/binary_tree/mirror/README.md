**Mirror of binary tree**

For a given Binary Tree of type integer, update it with its corresponding mirror image.\
Example:
![Mirror of binary tree](/assets/images/mirror_binary_tree.png)

**INPUT FORMAT**\
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

**OUTPUT FORMAT**\
The only line of output prints the mirrored tree in a level-wise order.\ 
Each level will be printed on a new line. Elements printed at each level will be separated by a single line.

**NOTE**\
You are not required to print anything explicitly. It has already been taken care of.

**CONSTRAINTS**\
1 <= N <= 10<sup>5</sup>\
Where N is the total number of nodes in the binary tree.\
Time Limit: 1 sec

**SAMPLE INPUT**\
```
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
```

**SAMPLE OUTPUT**\
1\
3 2\ 
7 6 5 4

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of node in binary tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of binary tree