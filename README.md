## INSTRUCTIONS AND RECOMMENDATIONS

1. Use the following command to compile the code: `gcc -std=c99 ieee754-calculator.c -o calculator`.
   - The flag `-std=c99` specifies that the C language standard to be used is C99. By adopting that standard, the program displays the IEEE-754 "exceptional cases" in a better format. For example, positive infinity will be automatically displayed in the command line as "inf" instead of "1.#INF00".