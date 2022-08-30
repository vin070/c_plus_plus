**Node with maximum child sum**

Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.

**INPUT FORMAT**\
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

**OUTPUT FORMAT**\
The first and only line of output contains the data of the node with maximum sum, as described in the task.

**CONSTRAINTS**\
Time Limit: 1 sec

**SAMPLE INPUT**
```
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
```

**SAMPLE OUTPUT**\
1

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of node in tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of tree
