**Print Reverse LinkedList**

You have been given a singly linked list of integers. Write a function to print the list in a reverse order.
To explain it further, you need to start printing the data from the tail and move towards the head of the list, printing the head data at the end.

**Note**: You can’t change any of the pointers in the linked list, just print it in the reverse order.

**INPUT FORMAT**\
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.\
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.\
Remember/Constraints: While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

**OUTPUT FORMAT**\
For each test case, print the singly linked list of integers in a reverse fashion, in a row, separated by a single space.\
Output for every test case will be printed in a seperate line.

**CONSTRAINTS**\
1 <= t <= 10^2\
0 <= M <= 10^3\
Time Limit: 1sec\
Where 'M' is the size of the singly linked list.

**SAMPLE INPUT**
```
1
1 2 3 4 5 -1
```

**SAMPLE OUTPUT**\
5 4 3 2 1

**TIME COMPLEXITY**\
T(n) = O(n) where n is length of linked list