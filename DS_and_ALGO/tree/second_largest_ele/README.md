**Second Largest Element In Tree**

Given a generic tree, find and return the node with second largest value in given tree.\
Note: Return NULL if no node with required value is present.

**INPUT FORMAT**\
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

**OUTPUT FORAMT**\
The first and only line of output contains data of the node with second largest data.

**CONSTRAINTS**\
Time Limit: 1 sec

**SAMPLE INPUT**
```
10 3 20 30 40 2 40 50 0 0 0 0 
```

**SAMPLE OUTPUT**\
40

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of nodes in tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of tree