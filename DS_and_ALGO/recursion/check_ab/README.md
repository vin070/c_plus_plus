**Check AB**

Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:\
a. The string begins with an 'a'\
b. Each 'a' is followed by nothing or an 'a' or "bb"\
c. Each "bb" is followed by nothing or an 'a'\
If all the rules are followed by the given string, return true otherwise return false.

**INPUT FORMAT**\
String S

**OUTPUT FORMAT**\
'true' or 'false'

**CONSTRAINTS**\
1 <= |S| <= 1000\
where |S| represents length of string S.

**SAMPLE INPUT 1**\
abb

**SAMPLE OUTPUT 1**\
true

**SAMPLE INPUT 2**\
abababa

**SAMPLE OUTPUT 2**\
false

**TIME COMPLEXITY**\
T(n) = O(n) where n is length of string.