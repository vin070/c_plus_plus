**Compress the String**

Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.\
If a string has 'x' repeated 5 times, replace this "xxxxx" with "x5".\
The string is compressed only when the repeated character count is more than 1.

**NOTE**\
Consecutive count of every character in the input string is less than or equal to 9.\
You are not required to print anything. It has already been taken care of. Just implement the given function.

**INPUT FORMAT**\
The first and only line of input contains a string without any leading and trailing spaces.\

**OUTPUT FORMAT**\
The output contains the string after compression printed in single line.

**CONSTRAINTS**\
0 <= N <= 10^6\
Where 'N' is the length of the input string.\
Time Limit: 1 sec

**SAMPLE INPUT 1**\
aaabbccdsa

**SAMPLE OUTPUT 1** \
a3b2c2dsa

**TIME COMPLEXITY**
O(n)