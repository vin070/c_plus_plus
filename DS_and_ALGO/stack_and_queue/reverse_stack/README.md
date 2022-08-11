**Reverse a Stack**

You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated and the other one is empty. You are required to write a function that reverses the populated stack using the one which is empty.\
For Example:\
![Reverse stack image](/assets/images/reverse-of-a-stack.png)

**INPUT FORMAT**\
The first line of input contains an integer N, denoting the total number of elements in the stack.\
The second line of input contains N integers separated by a single space, representing the order in which the elements are pushed into the stack.\

**OUTPUT FORMAT**\
The only line of output prints the order in which the stack elements are popped, all of them separated by a single space. 

**NOTE**\
You are not required to print the expected output explicitly, it has already been taken care of. Just make the changes in the input stack itself.

**CONSTRAINTS**\
1 <= N <= 10<sup>3</sup>\
-2<sup>31</sup> <= data <= 2<sup>31</sup> - 1\
Time Limit: 1sec

**SAMPLE INPUT**
```
6
1 2 3 4 5 10
```

**SAMPLE OUTPUT**\
1 2 3 4 5 10

**TIME COMPLEXITY**\
T(n) = O(n) where n is the size of stack

**SPACE COMPLEXITY**\
S(n) = O(n) where n is the size of stack