**Eliminate duplicates from linked list**

You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.

**INPUT FORMAT**\
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.\
The first and the only line of each test case or query contains the elements(in ascending order) of the singly linked list separated by a single space.\
Remember/Consider: While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

**OUTPUT FORMAT**\
For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.\
Output for every test case will be printed in a seperate line.

**CONSTRAINTS**\
1 <= t <= 10^2\
0 <= M <= 10^5\
Time Limit: 1sec\
Where 'M' is the size of the singly linked list.

**SAMPLE INPUT**
```
1
1 2 3 3 3 3 4 4 4 5 5 7 -1
```

**SAMPLE OUTPUT**\
1 2 3 4 5 7 

**TIME COMPLEXITY**\
T(n) = O(n) where n is length of linked list