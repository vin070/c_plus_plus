**Palindrome Linked List**

You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.

**INPUT FORMAT**\
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.\
First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.\
Remember/Consider: While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

**OUTPUT FORMAT**\
For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.

**CONSTRAINTS**\
1 <= t <= 10^2\
0 <= M <= 10^5\
Time Limit: 1sec\
Where 'M' is the size of the singly linked list.

**SAMPLE INPUT 1**
```
1
9 2 3 3 2 9 -1
```

**SAMPLE OUTPUT 1**\
true

**SAMPLE INPUT 2**
```
2
0 2 3 2 5 -1
-1
```

**SAMPLE OUTPUT 2**\
false\
true

**TIME COMPLEXITY**\
T(n) = O(n/2) where n is number of nodes in linked list