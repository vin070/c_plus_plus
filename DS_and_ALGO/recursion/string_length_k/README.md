**Strings of Length k**

Given a string S and an integer k, you need to find all the possible strings that can be made of size k using only characters present in string S.\
The characters can repeat as many times as needed.\
**Note** 1 : The number of output strings can be at max 1000.\
**Note** 2 : Order of strings in not important.

**INPUT FORMAT**\
S and k (separated by space)

**CONSTRAINTS**\
1 <= Length of String S <= 10\
1 <= k <= 5

**SAMPLE INPUT 1**\
```
abc 2
```

**SAMPLE OUTPUT 1**\
```
aa
ab
ac
ba
bb
bc
ca
cb
cc
```

**TIME COMPLEXITY**\
T(n) = O(n^k) where n is length of input string and k is length of any string in output array.

**SPACE COMPLEXITY**\
S(n) = O(n^k) where n is length of input string and k is length of any string in output array