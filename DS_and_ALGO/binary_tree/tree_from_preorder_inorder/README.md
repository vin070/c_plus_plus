**Construct Tree from Preorder and Inorder**

For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.

**Note**: Assume that the Binary Tree contains only unique elements. 

**INPUT FORMAT**\
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.\
The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.\
The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.

**OUTPUT FORMAT**\
The given input tree will be printed in a level order fashion where each level will be printed on a new line.\ 
Elements on every level will be printed in a linear fashion. A single space will separate them.

**CONSTRAINTS**\
1 <= N <= 10<sup>4</sup>\
Where N is the total number of nodes in the binary tree.\
Time Limit: 1 sec

**SAMPLE INPUT**
```
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
```

**SAMPLE OUTPUT**\
1\
2 3\
4 5 6 7 

**TIME COMPLEXITY**\
T(n) = O(n<sup>2</sup>) where n is size of preorder/inorder array length

**SPACE COMPLEXITY**\
S(n) = O(n) where n is size of preorder/inorder array length