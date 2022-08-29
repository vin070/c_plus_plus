Contains x

Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.

**INPUT FORMAT**\
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.\
The following line contains an integer, that denotes the value of x.

**OUTPUT FORMAT**
The first and only line of output contains true, if x is present and false, otherwise.

**CONSTRAINTS**\
Time Limit: 1 sec

**SAMPLE INPUT**
```
10 3 20 30 40 2 40 50 0 0 0 0
40
```

**SAMPLE OUTPUT**\
true

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of nodes in tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of tree