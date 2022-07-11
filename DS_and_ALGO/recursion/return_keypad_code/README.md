**Return keypad code**\
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.\
Note : 1. The order of strings are not important. 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.\

**INPUT FORMAT**\
Integer n

**OUTPUT FORMAT**\
All possible strings in different lines

**CONSTRAINTS**\-
1 <= n <= 10^6

**SAMPLE INPUT**\
23

**SAMPLE OUTPUT**\
ad\
ae\
af\
bd\
be\
bf\
cd\
ce\
cf

**TIME COMPLEXITY**\
T(n) = 4^n where n is number of digit.