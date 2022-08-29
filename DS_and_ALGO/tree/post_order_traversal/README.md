**Print tree in post order faishon**

Given a generic tree, print the post-order traversal of given tree.\
The post-order traversal is: visit child nodes first and then root node.

**INPUT FORMAT**\
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

**OUTPUT FORMAT**\
The first and only line of output contains the elements printed in post-order traversal. The elements in the output must be separated by a single space.

**CONSTRAINTS**\
Time Limit: 1 sec\

**SAMPLE INPUT**
```
10 3 20 30 40 2 400 50 0 0 0 0
```

**SAMPLE OUTPUT**\
400 50 20 30 40 10

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of node in tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of tree