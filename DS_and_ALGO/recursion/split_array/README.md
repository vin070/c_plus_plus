**Split Array**

Given an integer array A of size N, check if the input array can be splitted in two parts such that
- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.\
  Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.\
  Return true, if array can be split according to the above rules, else return false.

**Note**: You will get marks only if all the test cases are passed.

**INPUT FORMAT**\
Line 1 : Integer N (size of array)\
Line 2 : Array A elements (separated by space)

**OUTPUT FORMAT**\
true or false

**CONSTRAINTS**\
1 <= N <= 50

**SAMPLE INPUT 1**
```
2
1 2
```

**SAMPLE OUTPUT 1**\
false

**SAMPLE INPUT 2**
```
3
1 4 3
```
**SAMPLE OUTPUT 2**\
true

**TIME COMPLEXITY**\
T(n) = O(2^n) where n length of array.

**SPACE COMPLEXITY**\
S(n) = O(1)