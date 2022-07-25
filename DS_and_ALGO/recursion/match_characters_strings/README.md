**Does s contain t ?**

Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).\
Return true or false.\
Do it recursively.\
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.

**INPUT FORMAT**\
Line 1 : String s\
Line 2 : String t

**OUTPUT FORMAT**\
true or false

**SAMPLE INPUT 1**\
abchjsgsuohhdhyrikkknddg\
coding

**SAMPLE OUTPUT 1**\
true

**SAMPLE INPUT 2**\
abcde\
aeb

**SAMPLE OUTPUT 2**\
false

**TIME COMPLEXITY**\
T(n) = O(n) where n is length of string against which another string have to match. 

**SPACE COMPLEXITY**\
S(n) = O(n1 + n2) where n1 is length of first string and n2 is length of another string.