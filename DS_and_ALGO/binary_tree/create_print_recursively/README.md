**Create and print tree recursively**

Create a binary tree recursively and print that tree  in recursively. 
For any given node you will for asked for left child, if left child value is not -1, then it will again ask for left child for input child. If left child is -1, it will ask for right child in same faishon.
**Note**: If there is no left/right child just input -1

**SAMPLE INPUT**
```
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
```

**SAMPLE OUTPUT**\
8:L3\
3:L10\
10:L1\
1:L6R4\
6:R14\
14:\
4:L7\
7:L13\
13:

**TIME COMPLEXITY**\
T(n) = O(n) where n is number of node in binary tree

**SPACE COMPLEXITY**\
S(n) = O(h) where h is height of binary tree