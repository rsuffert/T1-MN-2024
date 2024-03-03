#include <stdio.h>
#include <stdlib.h>
#include <fenv.h>

void print_IEEE754_representation(float num);

int main(int argc, char* argv[])
{
    // test user input
    if (argc != 4) 
    {
        printf("Error: must provide three arguments: a number, an operand and another number.\n");
        return 1;
    }

    // convert user input
    char op    = argv[2][0];
    float val1 = strtof(argv[1], NULL);
    float val2 = strtof(argv[3], NULL);

    // perform operation according to user input operator
    feclearexcept(FE_ALL_EXCEPT); // clear all IEEE-754 exceptions before performing operation
    float res;
    switch(op)
    {
        case '+': res = val1 + val2; break;
        case '-': res = val1 - val2; break;
        case '/': res = val1 / val2; break;
        case 'x': res = val1 * val2; break;
        default: 
            printf("Invalid operation: '%c'.\n", op);
            return 1;
    }

    // results
    printf("\nResult (in decimals): %f %c %f = %f\n", val1, op, val2, res);

    printf("\nIEEE-754 binary representations:\n");
    printf("\tval1   = ");
    print_IEEE754_representation(val1);
    printf("\tval2   = ");
    print_IEEE754_representation(val2);
    printf("\tresult = ");
    print_IEEE754_representation(res);
    
    printf("\nIEEE-754 error flags:\n");
    printf("\tFE_DIVBYZERO = %d\n", fetestexcept(FE_DIVBYZERO)==0? 0 : 1);
    printf("\tFE_INEXACT   = %d\n", fetestexcept(FE_INEXACT)==0?   0 : 1);
    printf("\tFE_INVALID   = %d\n", fetestexcept(FE_INVALID)==0?   0 : 1);
    printf("\tFE_OVERFLOW  = %d\n", fetestexcept(FE_OVERFLOW)==0?  0 : 1);
    printf("\tFE_UNDERFLOW = %d\n\n", fetestexcept(FE_UNDERFLOW)==0? 0 : 1);

    return 0;
}

void print_IEEE754_representation(float num)
{
    // TODO: implement algorithm to actually print the IEEE-754 binary representation of the value passed as parameter
    printf("0 00000000 0000000000000000000000\n");
}
