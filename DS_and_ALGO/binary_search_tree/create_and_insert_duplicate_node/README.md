**Create and Insert duplicate node**

For a given a Binary Tree of type integer, duplicate every node of the tree and attach it to the left of itself.
The root will remain the same. So you just need to insert nodes in the given Binary Tree.

Example:\
![Binary search tree](/assets/images/binary_search_tree.png)\
After making the changes to the above-depicted tree, the updated tree will look like this.\
![Binary search tree duplicates](/assets/images/binary_search_tree_duplicates.png)

You can see that every node in the input tree has been duplicated and inserted to the left of itself.

**INPUT FORMAT**\
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

**OUTPUT FORMAT**\
The updated tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.

**NOTE**\
You are not required to print anything explicitly. It has already been taken care of. Just implement the function to achieve the desired structure of the tree.

**CONSTRAINTS**\
1 <= N <= 10<sup>5</sup>\
Where N is the total number of nodes in the binary tree.\
Time Limit: 1 sec

**SAMPLE INPUT**
```
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
```

**SAMPLE OUTPUT**\
10\
10 30\
20 30 60\
20 50 60\
40 50\
40

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of node is tree

**SPACE COMPLEXITY**\
S(n) = o(h) where h is height of tree