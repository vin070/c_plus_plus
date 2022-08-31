**Count number of nodes present in binary tree**

Create a binary tree recursively. For any given node you will for asked for left child, if left child value is not -1, then it will again ask for left child for input child. If left child is -1, it will ask for right child in same faishon.
**Note**: If there is no left/right child just input -1

**SAMPLE INPUT**
```
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
```

**SAMPLE OUTPUT**\
9

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of nodes in binary tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of binary tree