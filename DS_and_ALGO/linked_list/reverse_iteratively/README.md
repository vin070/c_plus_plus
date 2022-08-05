**Reverse linked list iteratively**

Given a singly linked list of integers, reverse it iteratively and return the head to the modified list.

**Note**\
No need to print the list, it has already been taken care. Only return the new head to the list.

**INPUT FORMAT**\
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.\
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.\
Remember/Consider: While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

**OUTPUT FORMAT**\
For each test case/query, print the elements of the updated singly linked list.\
Output for every test case will be printed in a separate line.

**CONSTRAINTS**\
1 <= t <= 10<sup>2</sup>\
0 <= N <= 10<sup>4</sup>\
Where N is the size of the singly linked list.\
Time Limit: 1 sec

**SAMPLE INPUT 1**
```
1
1 2 3 4 5 6 7 8 -1
```

**SAMPLE OUTPUT 1**\
8 7 6 5 4 3 2 1

**TIME COMPLEXITY**\
T(n) = O(n) where n is length of linked list