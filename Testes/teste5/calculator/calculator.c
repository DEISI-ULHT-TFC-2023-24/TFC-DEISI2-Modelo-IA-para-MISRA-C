/*List of Non-compliant Rules:
Rule 8.1: Functions shall have prototype declarations and the return type and parameters of a function shall be explicitly stated.
Rule 8.2: Function prototypes shall be declared and defined consistently.
Rule 10.1: The value of an expression of integer type should not be implicitly converted to a different underlying type.
Rule 13.4: The result of an assignment operator in a controlling expression (such as 
if
, 
while
, 
for
) shall be enclosed in parentheses.
Rule 14.3: Controlling expressions shall not contain assignments.
Rule 15.7: All if…else if constructs shall be terminated with an else statement.
Rule 17.7: The value returned by a function having non-void return type shall be used.
Rule 20.9: The input/output library 
<stdio.h>
 should be used cautiously.
Rule 21.6: The standard input/output functions should not be used directly without checking their return values.
Revised Code:*/

#include <stdio.h>     // Rule 20.9: Standard headers should be used as per ISO standard
#include <stdbool.h>   // Rule 20.9: Include <stdbool.h> for boolean types

// Function prototypes
static bool getInput(double *num1, double *num2, char *operator);
static void printResult(double result);
static double performOperation(double num1, double num2, char operator, bool *valid);

int main(void) { // Rule 8.1: Return type and parameters explicitly specified
    double num1 = 0.0;
    double num2 = 0.0;
    double result = 0.0;
    char operator = '\0';
    bool validOperation = false;

    if (!getInput(&num1, &num2, &operator)) {
        (void)printf("Invalid input\n");
        return 1; // Rule 17.7: Ensure all function return values are used
    }

    result = performOperation(num1, num2, operator, &validOperation);
    if (!validOperation) {
        (void)printf("Invalid operator\n"); // Rule 20.9: Use printf cautiously
        return 1; // Rule 17.7: Ensure all function return values are used
    }

    printResult(result);

    return 0;
}

static bool getInput(double *num1, double *num2, char *operator) {
    int ret;

    (void)printf("Enter first number: ");
    ret = scanf("%lf", num1);
    if (ret != 1) {
        return false;
    }

    (void)printf("Enter operator (+, -, *, /): "); // Rule 20.9: Use printf cautiously
    ret = scanf(" %c", operator);
    if (ret != 1) {
        return false;
    }

    (void)printf("Enter second number: ");
    ret = scanf("%lf", num2);
    if (ret != 1) {
        return false;
    }

    return true;
}

static void printResult(double result) {
    (void)printf("Result: %.2lf\n", result); // Rule 20.9: Use printf cautiously
}

static double performOperation(double num1, double num2, char operator, bool *valid) {
    double result = 0.0;
    *valid = true;  // Initialize as true

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0.0) {
                result = num1 / num2;
            } else {
                (void)printf("Division by zero error\n");
                *valid = false;
            }
            break;
        default:
            *valid = false;
            break;
    }

    return result;
}