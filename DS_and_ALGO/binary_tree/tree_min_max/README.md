**Min and Max of Binary Tree**

For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.\
Return the output as an object of Pair class, which is already created.

**Note**: All the node data will be unique and hence there will always exist a minimum and maximum node data.

**INPUT FORMAT**\
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

**OUTPUT FORMAT**\
The only line of output prints two integers denoting the minimum and the maximum data values respectively. A single line will separate them both.

**CONSTRAINTS**\
2 <= N <= 10<sup>5</sup>\
Where N is the total number of nodes in the binary tree.\
Time Limit: 1 sec

**SAMPLE INPUT**
```
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
```

**SAMPLE OUTPUT**\
1 14

**TIME COMPLEXITY**\
T(n) = O(n) where n number of node in tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h height of tree