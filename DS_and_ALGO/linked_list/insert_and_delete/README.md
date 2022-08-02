**Insert and delete node in linked list**

**INPUT FORMAT**\
t = where t is number of test cases\
n = where n number of input in linked list ended by -1\
insert index = Index where the data should be inserted\
data = The new data to be inserted\
delete index = Index of node which should be deleted

**OUTPUT FORMAT**\
Line 1 = Modified linked list after insertinig new node at given index\
Line 2 = Modified linked list after deleting node from  given index

**SAMPLE INPUT**
```
1
1 2 3 -1
0 100
0
```
**SAMPLE OUTPUT**\
1 2 3

**TIME COMPLEXITY**\
T(n) = O(n) for both insertion and delete operation on linked list, n is length of linked list.