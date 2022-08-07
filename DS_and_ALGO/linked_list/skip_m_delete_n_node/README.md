**Delete every N nodes**

You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.\
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.

**NOTE**\
No need to print the list, it has already been taken care. Only return the new head to the list.

**INPUT FORMAT**\
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.\
The first line of each test case or query contains the elements of the singly linked list separated by a single space.\
The second line of input contains two integer values 'M,' and 'N,' respectively. A single space will separate them.
Remember/Consider: While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

**OUTPUT FORMAT**\
For each test case/query, print the elements of the updated singly linked list.
Output for every test case will be printed in a seperate line.

**OCNSTRAINTS**\
1 <= t <= 10<sup>2</sup>\
0 <= P <= 10<sup>5</sup>\
Where P is the size of the singly linked list.\
0 <= M <= 10<sup>5</sup>\
0 <= N <= 10<sup>5</sup>\
Time Limit: 1sec

**SAMPLE INPUT 1**\
```
3
10 22 10 26 11 7 8 1 23 5 1 28 0 -1
2 3
1 2 3 4 5 -1
0 4
1 2 3 4 5 -1
0 0
```

**SAMPLE OUTPUT 1**\
10 22 7 8 1 28\
\
1 2 3 4 5

**TIME COMPLEXITY**\
T(n) = O(n) where n is length of linked list


