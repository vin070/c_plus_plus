**Reverse k nodes**

You are given a Singly Linked List of integers and an integer array 'B' of size 'N'. Each element in the array 'B' represents a block size. Modify the linked list by reversing the nodes in each block whose sizes are given by the array 'B'.

**Note**
1) If you encounter a situation when 'B[i]' is greater than the number of remaining nodes in the list, then simply reverse the remaining nodes as a block and ignore all the block sizes from 'B[i]'.

2) All block sizes are contiguous i.e. suppose that block 'B[i]' ends at a node cur, then the block 'B[i+1]' starts from the node just after the node cur.

**Example**\
Linked list: 1->2->3->4->5\
Array B: 3 3 5\
Output: 3->2->1->5->4

We reverse the first block of size 3 and then move to block 2. Now, since the number of nodes remaining in the list (2) is less than the block size (3), we reverse the remaining nodes (4 and 5) as a block and ignore all the block sizes that follow.

**INPUT FORMAT**\
The first line of the input contains the elements of the singly linked list separated by a single space and terminated by -1. Hence, -1 would not be a list element.

The second line contains a single integer 'N', denoting the size of the block array 'B'.

The third line contains 'N' single space-separated elements of the block array 'B'.

**OUTPUT FORMAT**\
You should return the modified linked list where elements should be single-space separated, terminated by -1.

**Note**\
You don't need to print the output, it has already been taken care of. Just implement the given function.

**CONSTRAINTS**\
0 <= L <= 5 * 10^5\
-10^9 <= data <= 10^9 and data != -1\
1 <= N <= 5 * 10^5\
0 <= B[i] <= 5 * 10^5\
Where 'L' is the number of nodes in the linked list and 'data' is the value of a node in the linked list. \
Time Limit: 1 sec

**SAMPLE INPUT 1**
```
1 2 3 4 5 6 7 8 9 10 11 -1
3
2 3 4
```
**SAMPLE OUTPUT 1**\
6 0 5 1 -1

**SAMPLE INPUT 2**
```
1 2 3 4 5 -1
10
1 0 0 1 0 0 1 1 1 0
```

**SAMPLE OUTPUT 2**\
1 2 3 4 5 -1

**TIME COMPLEXITY**\
T(n) = O(b*n) where n is length of linked list and b is size of block array.

