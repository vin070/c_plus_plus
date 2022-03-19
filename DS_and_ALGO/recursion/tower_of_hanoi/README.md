**Tower of Hanoi**\

Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move all disks from source rod to destination rod using third rod (say auxiliary). The rules are :\
1) Only one disk can be moved at a time.\
2) A disk can be moved only if it is on the top of a rod.\
3) No disk can be placed on the top of a smaller disk.\
Print the steps required to move n disks from source rod to destination rod.\
Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.

**INPUT FORMAT**\
Integer n

**OUTPUT FORMAT**\
Steps in different lines (in one line print source and destination rod name separated by space)

**CONSTRAINTS**\
0 <= n <= 20

**SAMPLE INPUT 1**\
2

**SAMPLE OUTPUT 1**\
a b\
a c\
b c

**SAMPLE INTPUT 2**\
3

**SAMPLE OUTPUT 2**\
a c\
a b\
c b\
a c\
b a\
b c\
a c

**TIME COMPLEXITY**\
0(2^n). Equation for finding time complexity is T(n) = 2T(n - 1) +1