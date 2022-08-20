**Minimum bracket Reversal**

For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.\
If the expression can't be balanced, return -1.\
Example:\
Expression: {{{{\
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.\
Expression: {{{\
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.

**INPUT FORMAT**\
The first and the only line of input contains a string expression, without any spaces in between.

**OUTPUT FORMAT**\
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.

**NOTE**\
You don't have to print anything. It has already been taken care of.

**CONSTRAINTS**\
0 <= N <= 10<sup>6</sup>\
Where N is the length of the expression.\
Time Limit: 1sec

**SAMPLE INPUT 1**
```
{{{
```

**SAMPLE OUTPUT 1**\
-1

**SAMPLE INPUT 2**
```
{{{{}}
```

**SAMPLE OUTPUT 2**\
1

**SAMPLE INPUT 3**
```
}{
```
**SAMPLE OUTPUT 2**\
2

**TIME COMPLEXITY**\
T(n) = O(n)

**SPACE COMPLEXITY**\
S(n) = O(n)
