#include <stdio.h>
#include <stdlib.h>
#include <fenv.h>
#include <stdint.h>

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
    printf("\n1. IEEE-754 error flags:\n");
    printf("\t1.1. FE_DIVBYZERO = %d\n", fetestexcept(FE_DIVBYZERO)==0?  0 : 1);
    printf("\t1.2. FE_INEXACT   = %d\n", fetestexcept(FE_INEXACT)==0?    0 : 1);
    printf("\t1.3. FE_INVALID   = %d\n", fetestexcept(FE_INVALID)==0?    0 : 1);
    printf("\t1.4. FE_OVERFLOW  = %d\n", fetestexcept(FE_OVERFLOW)==0?   0 : 1);
    printf("\t1.5. FE_UNDERFLOW = %d\n", fetestexcept(FE_UNDERFLOW)==0?  0 : 1);

    printf("\n2. IEEE-754 binary representations (S = sign, E = exponent & M = mantissa):\n");
    printf("\t\t%7s%5s%16s\n", "S", "E", "M");
    printf("\t2.1. val1   = ");
    print_IEEE754_representation(val1);
    printf("\t2.2. val2   = ");
    print_IEEE754_representation(val2);
    printf("\t2.3. result = ");
    print_IEEE754_representation(res);

    printf("\n3. Result (in decimals): %f %c %f = %f\n\n", val1, op, val2, res);

    return 0;
}

void print_IEEE754_representation(float num)
{
    // extract sign, exponent and mantissa bits
    uint32_t* ptr = (uint32_t*)&num;
    uint32_t sign = (*ptr >> 31) & 1;
    uint32_t exponent = (*ptr >> 23) & 0xFF;
    uint32_t mantissa = *ptr & 0x7FFFFF;

    // print sign bit
    printf("%d ", sign);

    // print exponent bits
    for (int i = 7; i >= 0; i--)
        printf("%d", (exponent >> i) & 1);
    printf(" ");

    // print mantissa bits
    for (int i = 22; i >= 0; i--)
        printf("%d", (mantissa >> i) & 1);
    printf("\n");
}