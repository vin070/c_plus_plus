**Bubble sort using linked list**

Given a singly linked list of integers, sort it using 'Bubble Sort.'

**Note**\
No need to print the list, it has already been taken care. Only return the new head to the list.

**INPUT FORMAT**\
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.\
Remember/Consider: While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

**OUTPUT FORMAT**\
For each test case/query, print the elements of the sorted singly linked list.\
Output for every test case will be printed in a seperate line.

**CONSTRAINTS**\
0 <= M <= 10^3\
Where M is the size of the singly linked list.\
Time Limit: 1sec

**SAMPLE INPUT 1**
```1
0 9 8 7 6 5 4 3 -1
```

**SAMPLE OUTPUT 1**\
 3 4 5 6 7 8 9 10 

**TIME COMPLEXITY**\
T(n) = O(n<sup>2</sup>) where n is length of linked list

**SPACE COMPLEXITY**\
S(n) = O(1)