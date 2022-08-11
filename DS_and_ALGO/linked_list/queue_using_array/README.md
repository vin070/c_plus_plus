**Queue using array**

Implement a Queue Data Structure specifically to store integer data using a Singly Linked List.\
The data members should be private.\
You need to implement the following public functions:
1. Constructor:
It initialises the data members as required.
2. push(data): This function should take one input from user. It pushes the element into the queue and returns nothing.
3. pop(): It removes the element from the front of the queue and in turn, returns nothing.
4. front(): It returns the element being kept at the front of the queue. In case the queue is empty, it returns default value for given data type.
5. get_size(): It returns the size of the queue at any given instance of time.
6. is_empty(): It returns a boolean value indicating whether the queue is empty or not.

Operations Performed on the Queue:\
Query-1(Denoted by an integer 1): Push a data to the queue.\
Query-2(Denoted by an integer 2): Remove the data from queue and return nothing.\
Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the front of the queue but doesn't remove it, unlike the dequeue function.\
Query-4(Denoted by an integer 4): Returns the current size of the queue.\
Query-5(Denoted by an integer 5): Returns a boolean value denoting whether the queue is empty or not.

**INPUT FORMAT**\
The first line contains an integer 'q' which denotes the number of queries to be run against each operation on the queue. 
Then the test cases follow.\
Every 'q' lines represent an operation that needs to be performed.\
For the enqueue operation, the input line will contain two integers separated by a single space, representing the type of the operation and the data being enqueued into the queue.\
For the rest of the operations on the queue, the input line will contain only one integer value, representing the query being performed on the queue.

**OUTPUT FORMAT**\
For Query-1, you do not need to return anything.\
For Query-2, prints the data being dequeued from the queue.\
For Query-3, prints the data kept on the front of the queue.\
For Query-4, prints the current size of the queue.\
For Query-5, prints 'true' or 'false'(without quotes).\
Output for every query will be printed in a separate line.

**NOTE**\
You are not required to print anything explicitly. It has already been taken care of. Just implement the functions.

**CONSTRAINTS**\
1 <= q <= 10<sup>5</sup>\
1 <= x <= 5\
-2<sup>31</sup> <= data <= 2<sup>31</sup> - 1 and data != -1\
Where 'q' is the total number of queries being performed on the queue, 'x' is the range for every query and data represents the integer pushed into the queue.\
Time Limit: 1 second

**SAMPLE INPUT**
```
7
1 17
1 23
1 11
2
2
2
2
```

**SAMPLE OUTPUT**\
17\
23\
1\
-1

**TIME COMPLEXITY**\
T(n) = O(n) for push operation where n is the size of queue before push operation.\
       O(1) for other operation.

**SPACE COMPLEXITY**\
S(n) = O(1)