**Swap two nodes of linked list**

You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.

**Note**\
Remember, the nodes themselves must be swapped and not the datas.\
No need to print the list, it has already been taken care. Only return the new head to the list.

**INPUT FORMAT**\
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.\
The first line of each test case or query contains the elements of the singly linked list separated by a single space.\
The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.\
Remember/consider: While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

**OUTPUT FORMAT**\
For each test case/query, print the elements of the updated singly linked list.\
Output for every test case will be printed in a seperate line.

**CONSTRAINTS**\
1 <= t <= 10<sup>2</sup>\
0 <= M <= 10<sup>5</sup>\
Where M is the size of the singly linked list.\
0 <= i < M\
0 <= j < M\
Time Limit: 1sec

**SAMPLE INPUT**
```
4
1 2 3 4 5 6 -1
2 3
1 2 3 4 5 6 -1
0 2
1 2 3 -1
0 1
1 1 2 -1
0 0
1 2 3 4 5 6 -1
1 4
```

**SAMPLE OUTPUT**\
1 2 4 3 5 6\
3 2 1 4 5 6\
2 1 3\
1 1 2

**TIME COMPLEXITY**\
T(n) = O(n) where n is length of linked list