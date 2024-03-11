### 1. Compiling the code
Use the following command to compile the code: `gcc -std=c99 ieee754-calculator.c -o calculator`. The flag `-std=c99` specifies that the C language standard to be used is C99. By adopting that standard, the program displays the IEEE-754 "exceptional cases" in a better format. For example, positive infinity will be automatically displayed in the command line as "inf" instead of "1.#INF00".

### 2. Inputting data
The program receives its inputs through command line arguments. It expects three arguments in the following format: **<operand1> <operator> <operand2>**.
- The operands are any numeric values, including numbers in scientific notation in the format *xey*, where *x* is the mantissa and *y* is the exponent, considering base 10. The operands may also be "inf" and "-inf" (representing positive and negative infinity, respectively) and "nan" and "-nan" (representing positive and negative non-numeric values, respectively), according to the IEEE-754 standard.
- The operator may be any of the following: '+', '-', '/', 'x', representing the four basic arithmetic operations.

### 3. Errors
The program also informs error messages through the command line, which are preceded by **[ERROR]** to indicate failure. Then, the user should re-run the program and correct the indicated errors in the arguments provided.