// Terminal-Based Calculator
//
// Perform basic arithmetic operations on integers based on text input.
//
// Author: Ryan Ling
//
// Created: 24/6/2025
// Last Updated: 26/6/2025

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

typedef struct {
    const char *const chars;
    int32_t length;
} ConstString;

void evaluateExpression(char *input);
bool isNumerical(char *str);
int add(int add1, int add2);
int sub(int sub1, int sub2);
int mult(int mult1, int mult2);
int divide(int div1, int div2);

const int INPUT_LIMIT = 30;
const int NUMS_LENGTH = 2;

const char *const MSG_INTRO =
    "=====================================================================\n"
    "==================== BASIC ARITHMETIC CALCULATOR ====================\n"
    "=====================================================================\n"
    "Hello there! Enter an expression or type '?' to get started. (^w^)\n";
const char *const MSG_HELP =
    "============================= HELP GUIDE ============================\nThe"
    " available operations are:\n   - addition (+)\n   - subtraction (-)\n   "
    "- multiplication (*)\n   - division (/)\n\n- When entering expressions, do"
    " not use spaces or commas.\n- Type 'end' to exit the program.\n\n";
const char *const MSG_PROMPT = "> ";
const char *const MSG_ERROR_INVALID_EXPRESSION =
    "Invalid input. The formatting of your query may be incorrect. Type "
    "'?' for further help.\n";
const char *const MSG_ERROR_INVALID_OPERATION =
    "Operation not recognised. Enter 'guide' for further help.\n";

ConstString QUERY_HELP = {"?", 1};
ConstString QUERY_EXIT = {"end", 3};

int main() {
    char *input = malloc(INPUT_LIMIT);
    bool exit = false;

    printf("%s", MSG_INTRO);
    
    while (exit == false) {
        printf("%s", MSG_PROMPT);
        fgets(input, INPUT_LIMIT + 1, stdin);

        if (strncmp(input, QUERY_HELP.chars, QUERY_HELP.length) == 0) {
            printf("%s", MSG_HELP);
        } else if (strncasecmp(input, QUERY_EXIT.chars, QUERY_EXIT.length) == 0) {
            exit = true;
        } else {
            evaluateExpression(input);
        }
    }

    return 0;
}

// Evaluates an expression query & outputs its answer.
void evaluateExpression(char *input) {
    char *strNums[NUMS_LENGTH]; // TODO - check how to create array of strings
    int nums[NUMS_LENGTH];
    char op;
    bool valid = false;
    int result = 0;

    // Scan input to determine operation & the integers being operated on
    // TODO - modify to allow for multiple operations & brackets
    // TODO - modify to allow for decimal inputs
    // TODO - search input for integers & operation

    // Check inputs & convert numerical strings to int data type
    for (int i = 0; i < NUMS_LENGTH; i++) {
        if (isNumerical(strNums[i]) == true) {
            nums[i] = atoi(strNums[i]);
        } else {
            printf("'%s' is not an integer.\n", strNums[i]);
        }
    }
    
    // Perform operation(s)
    /*switch (op) {
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
    }*/

    if (valid == true) {
        printf("Answer: %d", result);
    }
}

// Checks whether the given string contains only numerical characters.
bool isNumerical(char *str) {
    bool isNum = false;
    // TODO
    return isNum;
}

///////////////////////////////// OPERATIONS ///////////////////////////////////

// Returns the sum of two integers.
int add(int add1, int add2) {
    int sum = add1 + add2;
    return sum;
}

// Returns the difference of two integers.
int sub(int sub1, int sub2) {
    int diff = sub1 - sub2;
    return diff;
}

// Returns the product of two integers.
int mult(int mult1, int mult2) {
    int prod = mult1 * mult2;
    return prod;
}

// Returns the quotient of two integers.
int divide(int div1, int div2) {
    int quot = div1 / div2; // TODO - modify to allow for float results
    return quot;
}