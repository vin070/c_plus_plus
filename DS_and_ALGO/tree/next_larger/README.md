**Next larger**

Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.\
**Note**: Return NULL if no node is present with the value greater than n.

**INPUT FORMAT**\
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.\  
The following line contains an integer, that denotes the value of n.

**OUTPUT FORMAT**\
The first and only line of output contains data of the node, whose data is just greater than n.

**CONSTRAINTS**\
Time Limit: 1 sec

**SAMPLE INPUT**
```
10 3 20 30 40 2 40 50 0 0 0 0 
18
```

**SAMPLE OUTPUT**\
20

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of nodes in tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of tree