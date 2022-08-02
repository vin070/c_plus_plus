**Find a Node in Linked List**

You have been given a singly linked list of integers. Write a function that returns the index/position of integer data denoted by 'N' (if it exists). Return -1 otherwise.\
**Note**:Assume that the Indexing for the singly linked list always starts from 0.

**INPUT FORMAT**\
The first line contains an Integer 'T' which denotes the number of test cases.\
The first line of each test case or query contains the elements of the singly linked list separated by a single space. \
The second line contains the integer value 'N'. It denotes the data to be searched in the given singly linked list.\
Remember/Consider: While specifying the list elements for input, -1 indicates the end of the singly linked list and hence -1 would never be a list element.

**OUTPUT FORMAT**\
For each test case, return the index/position of 'N' in the singly linked list. Return -1, otherwise.\
Output for every test case will be printed in a separate line.
**Note**: You do not need to print anything; it has already been taken care of. Just implement the given function.

**CONSTRAINTS**\
1 <= T <= 10^2\
0 <= M <= 10^5\
Where 'M' is the size of the singly linked list.\
Time Limit: 1 sec

**SAMPLE INPUT**
```
2
3 4 5 2 6 1 9 -1
5
10 20 30 40 50 60 70 -1
6
```

**SAMPLE OUTPUT**\
2\
-1

**TIME COMPLEXITY**\
T(n) = O(n) where n is length of linked list