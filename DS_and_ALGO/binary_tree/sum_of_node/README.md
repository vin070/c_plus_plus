**Sum Of Nodes**

For a given Binary Tree of integers, find and return the sum of all the nodes data.

**INPUT FORMAT**\
The first and the only line of input will contain the nodes data, all separated by a single space.\
Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

**OUTPUT FORMAT**\
The first and the only line of output prints the sum of all the nodes data present in the binary tree.

**NOTE**\
You are not required to print anything explicitly. It has already been taken care of.

**CONSTRAINTS**\
1 <= N <= 10<sup>6</sup>\
Where N is the total number of nodes in the binary tree.\
Time Limit: 1 sec


**SAMPLE INPUT**
```
2 3 4 6 -1 -1 -1 -1 -1
```

**SAMPLE OUTPUT**\
15

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of nodes in binary tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of binary tree