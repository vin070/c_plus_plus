**Shift last n nodes to first**

You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.

**INPUT FORMAT**\
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.\
The first line of each test case or query contains the elements of the singly linked list separated by a single space.\
The second line contains the integer value 'N'. It denotes the number of nodes to be moved from last to the front of the singly linked list.\
Remember/Consider: While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

**OUTPUT FORMAT**\
For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.\
Output for every test case will be printed in a seperate line.

**CONSTRAINTS**\
1 <= t <= 10^2\
0 <= M <= 10^5\
0 <= N < M\
Time Limit: 1sec\
Where 'M' is the size of the singly linked list.

**SAMPLE INPUT**
```
2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5
```
**SAMPLE OUTPUT**\
3 4 5 1 2\
20 30 40 50 60 10

**TIME COMPLEXITY**\
T(n) = O(n) where n is length of linked list