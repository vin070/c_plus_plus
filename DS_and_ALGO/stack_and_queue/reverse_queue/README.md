**Reverse Queue**

You have been given a queue that can store integers as the data. You are required to write a function that reverses the populated queue itself without using any other data structures.

Normal queue
![Normal queue](/assets/images/queue.png)

Reverse queue
![Reverse queue](/assets/images/reverse_queue.png)

**INPUT FORMAT**\
The first list of input contains an integer 't' denoting the number of test cases/queries to be run.
Then the test cases follow.\
The first line input for each test case/query contains an integer N, denoting the total number of elements in the queue.\
The second line of input contains N integers separated by a single space, representing the order in which the elements are enqueued into the queue.

**OUTPUT FORMAT**\
For each test case/query, the only line of output prints the order in which the queue elements are dequeued, all of them separated by a single space.\
Output for every test case/query will be printed on a new line.

**NOTE**\
You are not required to print the expected output explicitly, it has already been taken care of. Just make the changes in the input queue itself.

**CONSTRAINTS**\
1 <= t <= 100\
1 <= N <= 10<sup>4</sup>\
-2<sup>31</sup> <= data <= 2<sup>31</sup> - 1\
Time Limit: 1sec

**SAMPLE INPUT**

```
1
6
1 2 3 4 5 10
```

**TIME COMPLEXITY**\
T(n) = O(n) where n is length of queue

**SPACE COMPLEXITY**\
S(n) = O(n) where n is length of queue
