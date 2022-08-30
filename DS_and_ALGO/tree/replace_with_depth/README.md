**Replace with depth**

You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return or print anything.

**INPUT FORMAT**\
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

**OUTPUT FORMAT**\
The updated tree is printed level wise. Each level is printed in a new line. Please refer to sample output for more details. 

**CONSTRAINTS**\
Time Limit: 1 sec

**SAMPLE INPUT**
```
10 3 20 30 40 2 40 50 0 0 0 0
```

**SAMPLE OUTPUT**\
0:1,1,1
1:2,2
1:
1:
2:
2:

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of nodes in tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of tree