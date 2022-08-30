**Structurally identical**

Given two generic trees, return true if they are structurally identical. Otherwise return false.\
If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, then the trees are called structurally identical.  

**INPUT FORMAT**\
The first line of input contains data of the nodes of the first tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.\
The following line of input contains data of the nodes of the second tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

**OUTPUT FORMAT**\
The first and only line of output contains true, if the given trees are structurally identical and false, otherwise.

**CONSTRAINTS**\
Time Limit: 1 sec

**SAMPLE INPUT**
```
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 20 30 40 2 40 50 0 0 0 0
```

**SAMPLE OUTPUT**\
true

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of nodes in identical tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of identical tree