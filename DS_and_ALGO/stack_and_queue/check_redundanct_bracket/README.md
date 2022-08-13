**Check redundant brackets**

For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.\
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.\
Example:\
Expression: (a+b)+c\
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))\
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.\

**NOTE**\
You will not get a partial score for this problem. You will get marks only if all the test cases are passed.\
You are not required to print the expected result. It has already been taken care of.

**INPUT FORMAT**\
The first and the only line of input contains a string expression, without any spaces in between.

**OUTPUT FORMAT**\
The first and the only line of output will print either 'true' or 'false'(without the quotes) denoting whether the input expression contains redundant brackets or not.

**CONSTRAINTS**\
0 <= N <= 10<sup>6</sup>\
Where N is the length of the expression.\
Time Limit: 1 second

**SAMPLE INPUT 1**

```
a+(b)+c
```

**SAMPLE OUTPUT 1**\
true

**TIME COMPLEXITY**\
T(n) = O(n) where n is length of string

**SPACE COMPLEXITY**\
S(n) = O(n) where n is length of string
