// Calculator
//
// Perform basic arithmetic operations on integers based on text input.
//
// Author: Ryan Ling
//
// Written: 24/6/2025

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int add(int add1, int add2);
int sub(int sub1, int sub2);
int mult(int mult1, int mult2);
int divide(int div1, int div2); // TODO - modify to allow for float results

const char *const MSG_INTRO =
    "===================================\n=== BASIC ARITHMETIC CALCULATOR ===\n"
    "===================================\nPerform integer addition (+), "
    "subtraction (-), multiplication (*) or division (/). When entering "
    "expressions, do not use spaces. Enter \"end\" to terminate program.\n";
const char *const MSG_PROMPT_EXPRESSION = "Enter expression: \n> ";
const char *const MSG_ERROR_INVALID_OPERATION =
    "Operation not recognised. The only operations available are:\n- addition "
    "(+)\n- subtraction (-)\n- multiplication (*)\n- division (/)\n";
const char *const MSG_ERROR_INVALID_EXPRESSION =
    "Invalid input. The formatting of your query may be incorrect.\n";

int main() {
    int in1 = 0;
    int in2 = 0;
    char op = '0';
    bool valid = false;
    int result = 0;

    printf("%s", MSG_INTRO);
    printf("%s", MSG_PROMPT_EXPRESSION);
    scanf("%d%c%d", &in1, &op, &in2);

    // Scan input to determine operation & the integers being operated on
    // TODO - search input for 1st integer
    // TODO - search input for operation
    // TODO - search input for 2nd integer
    // TODO - modify to allow for multiple operations & integers
    // TODO - modify to allow for decimal inputs
    
    // Perform operation(s)
    switch (op) {
        case '+':
            result = add(in1, in2);
            valid = true;
            break;
        case '-':
            result = sub(in1, in2);
            valid = true;
            break;
        case '*':
            result = mult(in1, in2);
            valid = true;
            break;
        case '/':
            result = divide(in1, in2);
            valid = true;
            break;
        default:
            printf("%s", MSG_ERROR_INVALID_OPERATION);
            break;
    }

    if (valid == true) {
        printf("Answer: %d", result);
    }

    return 0;
}

// Returns the sum of two integers given by the user.
int add(int add1, int add2) {
    int sum = add1 + add2;
    return sum;
}

// Returns the difference of two integers given by the user.
int sub(int sub1, int sub2) {
    int diff = sub1 - sub2;
    return diff;
}

// Returns the product of two integers given by the user.
int mult(int mult1, int mult2) {
    int prod = mult1 * mult2;
    return prod;
}

// Returns the decimal quotient of two integers given by the user.
int divide(int div1, int div2) {
    int quot = div1 / div2;
    return quot;
}