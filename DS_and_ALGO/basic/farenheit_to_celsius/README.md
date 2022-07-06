**Fahrenheit to Celsius Table** \
Given three values - Start Fahrenheit Value (S), End Fahrenheit value (E) and Step Size (W), you need to convert all Fahrenheit values from Start to End at the gap of W, into their corresponding Celsius values and print the table.

**INPUT FORMAT** \
3 integers - S, E and W respectively

**OUTPUT FORMAT** \
Fahrenheit to Celsius conversion table. One line for every Fahrenheit and Celsius Fahrenheit value. Fahrenheit value and its corresponding Celsius value should be separate by tab ("\t")

**CONSTRAINTS** \
0 <= S <= 1000
0 <= E <= 1000
0 <= W <= 1000

**SAMPLE INPUT 1** \
0 
100 
20

**SAMPLE OUTPUT 1** \
0   -17
20  -6
40  4
60  15
80  26
100 37

**SAMPLE INPUT 2** \
120 
200 
40

**SAMPLE OUTPUT 2** \
120 48
160 71
200 93

**TIME COMPLEXITY** \
O((farenheit_end - farenheit_start + step+size)/step_size)

**FORMULA USED** \
F = (9/5) + 32;