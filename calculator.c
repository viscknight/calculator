// CLI-Based Calculator
//
// Perform basic arithmetic operations on integers based on text input.
//
// Author: Ryan Ling
//
// Created: 24 Jun 2025
// Last Updated: 13 Aug 2025

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////// DATA TYPES //////////////////////////////////

typedef struct {
    const char *const chars;
    int32_t length;
} ConstString;

////////////////////////////////// CONSTANTS ///////////////////////////////////

const int INPUT_LIMIT = 30;
const int MAX_NUM_DIGITS = 10;

const char *const MSG_INTRO =
    "=======================================================================\n"
    "===================== BASIC ARITHMETIC CALCULATOR =====================\n"
    "=============== (AKA: an incredibly rudimentary Matlab) ===============\n"
    "=======================================================================\n"
    "Enter an expression to get started, or enter '?' for help. (^w^) Enter \n"
    "'end' to exit the program.\n";
const char *const MSG_PROMPT = "> ";
const char *const MSG_HELP =
    "============================= HELP GUIDE ==============================\n"
    "The available operations are:\n  - addition (+)\n  - subtraction (-)\n  "
    "- multiplication (*)\n  - division (/)\n\n- When entering expressions, do "
    "not use spaces or commas.\n- Only the first 30 characters in a query will "
    "be read by the program.\n\n";
const char *const MSG_ERROR_INVALID =
    "This query is not a recognised command or valid expression. Enter '?' for "
    "further help.\n";
const char *const MSG_ERROR_INVALID_EXPRESSION =
    "Your expression contains a character that is not a digit or recognised "
    "operation. Enter '?' for further help.\n";
const char *const MSG_EXIT = "Bye! (>wo)/~\n";

ConstString CMD_HELP = {"?", 1};
ConstString CMD_EXIT = {"end", 3};

ConstString OP = {"+-*/", 4};

///////////////////////////// FUNCTION PROTOTYPES //////////////////////////////

bool containsNum(char *str);
bool containsInvalidChar(char *str);
int64_t evaluateExpression(char *str);
int64_t add(int64_t nums[]);
int64_t sub(int64_t nums[]);
int64_t mult(int64_t nums[]);
int64_t divide(int64_t nums[]);

////////////////////////////////// FUNCTIONS ///////////////////////////////////

int main() {
    char *input = malloc(INPUT_LIMIT + 1 * sizeof(char));
    bool exit = false;

    printf("%s", MSG_INTRO);
    
    while (exit == false) {
        printf("%s", MSG_PROMPT);
        fgets(input, INPUT_LIMIT + 1, stdin);

        // Process user input
        if (strncmp(input, CMD_HELP.chars, CMD_HELP.length) == 0) {
            printf("%s", MSG_HELP);
        } else if (strncmp(input, CMD_EXIT.chars, CMD_EXIT.length) == 0) {
            printf("%s", MSG_EXIT);
            exit = true;
        } else if (containsNum(input) == false) {
            printf("%s", MSG_ERROR_INVALID);
        } else if (containsInvalidChar(input) == true) {
            printf("%s", MSG_ERROR_INVALID_EXPRESSION);
        } else {
            printf("%lld\n", evaluateExpression(input));
        }
    }

    return 0;
}

// Checks whether the given string contains any numerical characters.
bool containsNum(char *str) {
    bool containsNum = false;

    for (size_t i = 0; i < strlen(str); i++) {
        if (isdigit(str[i]) != 0) containsNum = true;
    }

    return containsNum;
}

// Checks whether the given string contains any invalid characters (i.e. any
// non-numerical characters that are not a recognised operation character).
bool containsInvalidChar(char *str) {
    bool isInvalid = false;

    for (size_t i = 0; (i < strlen(str) - 1) && (isInvalid == false); i++) {
        if (isdigit(str[i]) == 0) {
            // Check if the current char being evaluated is a recognised
            // operation character
            for (int32_t j = 0; j < OP.length; j++) {
                if (str[i] == OP.chars[j]) {
                    isInvalid = false;
                    j = OP.length;
                } else {
                    isInvalid = true;
                }
            }
        }
    }

    return isInvalid;
}

// Evaluates an expression query & outputs its answer.
int64_t evaluateExpression(char *str) {
    int32_t numCount = 2;
    int64_t nums[numCount];
    char op = '\0';
    int64_t result = 0;

    // TODO - modify to allow for multiple operations & brackets
    // TODO - modify to allow for decimal inputs

    // Determine operation & the integers being operated on
    for (int i = 0; i < numCount; i++) nums[i] = 0;

    // Determine 2nd integer - TODO
    int8_t j = strlen(str);
    while (isdigit(str[j]) == 0) j--; // Get index of rightmost digit

    int8_t k = 0;
    int64_t place = 1;
    while (isdigit(str[j]) != 0) {
        nums[k] += (str[j] - '0') * place;
        place *= 10;
        j--;
        printf("%lld - 0x%llx (place: %lld)\n", nums[k], nums[k], place);
    }

    // Determine operation - TODO
    
    // Determine 1st integer - TODO
    
    // Perform operation
    if (op == OP.chars[0]) {
        result = add(nums);
    } else if (op == OP.chars[1]) {
        result = sub(nums);
    } else if (op == OP.chars[2]) {
        result = mult(nums);
    } else if (op == OP.chars[3]) {
        result = divide(nums);
    } else if (op == '\0') {
        result = nums[0];
    } else {
        printf("'%c' is not a valid operation.\n", op);
    }

    return result;
}

////////////////////////////////// Operations //////////////////////////////////
// NOTE: Operations are split into functions for future functionality updates.

// Returns the sum of two integers.
int64_t add(int64_t nums[]) {
    long sum = nums[0] + nums[1];
    return sum;
}

// Returns the difference of two integers.
int64_t sub(int64_t nums[]) {
    long diff = nums[0] - nums[1];
    return diff;
}

// Returns the product of two integers.
int64_t mult(int64_t nums[]) {
    long prod = nums[0] * nums[1];
    return prod;
}

// Returns the quotient of two integers.
int64_t divide(int64_t nums[]) {
    long quot = nums[0] / nums[1]; // TODO - modify to allow for float results
    return quot;
}