#include <stdio.h>
#include <stdlib.h>
#include <fenv.h>

int main(int argc, char *argv[]) {
    if (argc != 4) 
    {
        printf("Error: must provide three arguments: a number, an operand and another number.\n");
        return 1;
    }

    char op    = argv[2][0];
    float val1 = strtof(argv[1], NULL);
    float val2 = strtof(argv[3], NULL);

    feclearexcept(FE_ALL_EXCEPT); // clear all IEEE-754 exceptions before performing operation

    float res;
    switch(op)
    {
        case '+': res = val1 + val2; break;
        case '-': res = val1 - val2; break;
        case '/': res = val1 / val2; break;
        case '*': res = val1 * val2; break;
        default: 
            printf("Invalid operation: '%c'.\n", op);
            return 1;
    }

    printf("\nResult: %f %c %f = %f\n\n", val1, op, val2, res);
    printf("IEEE-754 error flags:\n");
    printf("\tFE_DIVBYZERO = %d\n", fetestexcept(FE_DIVBYZERO)==0? 0 : 1);
    printf("\tFE_INEXACT   = %d\n", fetestexcept(FE_INEXACT)==0?   0 : 1);
    printf("\tFE_INVALID   = %d\n", fetestexcept(FE_INVALID)==0?   0 : 1);
    printf("\tFE_OVERFLOW  = %d\n", fetestexcept(FE_OVERFLOW)==0?  0 : 1);
    printf("\tFE_UNDERFLOW = %d\n", fetestexcept(FE_UNDERFLOW)==0? 0 : 1);

    return 0;
}
