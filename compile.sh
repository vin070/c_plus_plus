 
#!/bin/bash
FILENAME="practice.cpp"
echo '---ENTER FILE NAME---'
read FILENAME
echo '---COMPILING START---'
g++ ${FILENAME}
echo '---COMPILING DONE---'

echo '---EXECUTION START---'
./$(dirname $0)/a.out
echo '---EXECUTION DONE---'
rm $(dirname $0)/a.out