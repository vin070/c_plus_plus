**Loot Houses**

A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

**INPUT FORMAT**\
The first line of input contains an integer value of 'n'. It is the total number of houses.\
The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.

**OUTPUT FORMAT**\
Print the the maximum money that can be looted.

**CONSTRAINTS**\
0 <= n <= 10 ^ 4\
Time Limit: 1 sec

**SAMPLE INPUT**\
6\
10 2 30 20 3 50

**SAMPLE OUTPUT**\
90

Explanation of Sample Output\
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.

**TIME COMPLEXITY**\
O(n) where n is length of array