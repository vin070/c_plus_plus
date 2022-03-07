**Given a decimal number (integer N), convert it into binary and print.The binary number should be in the form of an integer.**

**Note:** The given input number could be large, so the corresponding binary number can exceed the integer range. So you may want to take the answer as long for CPP and Java.

**Note:** For C++ coders: Do not use the inbuilt implementation of "pow" function. The implementation of that function is done for 'double's and it may fail when used for 'int's, 'long's, or 'long long's. Implement your own "pow" function to work for non-float data types.

**INPUT FORMAT** \
Integer N

**OUTPUT FORMAT** \
Corresponding Binary number (long)

**CONSTRAINTS** \
0 <= N <= 10^5

**SAMPLE INPUT** \
12

**SAMPLE OUTPUT** \
1100

**TIME COMPLEXITY** \
O(log2(n))