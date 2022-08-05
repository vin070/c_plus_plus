**Merge two sorted linked list**

You have been given two sorted(in ascending order) singly linked lists of integers.\
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.\
**Note**: Try solving this in O(1) auxiliary space.\
No need to print the list, it has already been taken care.

**INPUT FORMAT**\
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.\
The first line of each test case or query contains the elements of the first sorted singly linked list separated by a single space.\
The second line of the input contains the elements of the second sorted singly linked list separated by a single space.\
Remember/Consider: While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

**OUTPUT FORMAT**\
For each test case/query, print the resulting sorted singly linked list, separated by a single space.\
Output for every test case will be printed in a seperate line.

**CONSTRAINTS**\
1 <= t = 10^2\
0 <= N <= 10 ^ 4\
0 <= M <= 10 ^ 4\
Where N and M denote the sizes of the singly linked lists.\
Time Limit: 1sec

**SAMPLE INPUT 1**
```
1
2 5 8 12 -1
3 6 9 -1
```

**SAMPLE OUTPUT 1**\
2 3 5 6 8 9 12 

**SAMPLE INPUT 2**
```
1
-1
-1
```

**SAMPLE OUTPUT 2**


**TIME COMPLEXITY**\
T(n) = (minimum of n1 and n2) where n1 is length of 1<sup>st</sup> linked list and n2 is length of 2<sup>nd</sup> linked list.

**SPACE COMPLEXITY**\
S(n) = O(1)