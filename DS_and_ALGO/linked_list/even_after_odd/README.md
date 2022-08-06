**Even after odd linked list**

For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.

**Note**\
No need to print the list, it has already been taken care. Only return the new head to the list.

**INPUT FORMAT**\
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.\
The first line of each test case or query contains the elements of the singly linked list separated by a single space.\
Remember/Consider: While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

**OUTPUT FORMAT**\
For each test case/query, print the elements of the updated singly linked list.\
Output for every test case will be printed in a seperate line.

**CONSTRAINTS**\
1 <= t <= 10<sup>2</sup>\
0 <= M <= 10<sup>5</sup>\
Where M is the size of the singly linked list.\
Time Limit: 1sec

**SAMPLE INPUT 1**
```
3
1 2 3 4 5 -1
2 4 6 -1
1 3 5 -1
```

**SAMPLE OUTPUT 1**\
1 3 5 2 4\
2 4 6\
1 3 5

**TIME COMPLEXITY**\
T(n) = O(n) where n is length of linked list