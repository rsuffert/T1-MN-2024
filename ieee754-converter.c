#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) 
    {
        printf("Error: must provide three arguments: a number, an operand and another number.\n");
        return 1;
    }

    char op    = argv[2][0];
    float val1 = strtof(argv[1], NULL);
    float val2 = strtof(argv[3], NULL);

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

    printf("Result: %f\n", res);

    return 0; // Return 0 to indicate successful execution
}
