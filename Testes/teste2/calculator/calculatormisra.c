/*Your code already adheres to a majority of the mandatory MISRA C 2012 rules 1-23. Here are some that can be made more explicit:

Rule 2.2 (Required): There shall be no dead code.
Your code does not have any dead code.
Rule 4.1 (Required): Octal constants and escape sequences shall not be used.
Your code does not use octal constants or escape sequences.
Rule 8.2 (Required): Function types shall be in prototype form with parameter types specified.
The main function is correctly defined as 
int main(void)
.
Rule 9.1 (Required): The value of an object with automatic storage duration shall not be read before it has been set.
You should initialize 
result
 variable at declaration time.
Rule 10.1 (Required): Operands shall not be of an inappropriate essential type.
In your code, there are no such instances.
Rule 13.2 (Required): The value of an expression and its persistent side effects shall be the same under all permitted evaluation orders.
No violations detected in your code.
Rule 21.3 (Required): The functions of shall not be used.
Your code does not use functions from .
Here's your updated code:*/

#include <stdio.h>

int main(void) {
    double num1, num2;
    double result = 0.0;   /* Rule 9.1 */
    char operator;

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter second number: ");
    scanf("%lf", &num2);

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
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero\n");
                return 1; 
            }
            break;
        default:
            printf("Invalid operator");
            return 1;
    }

    printf("Result: %.2lf\n", result);
    return 0;
}

/*
The rest of the mandatory rules from 1 to 23 do not apply because they are about specific constructs that your code does not use or has already followed. These include:

Rule 1.3: No occurrence of undefined or critical unspecified behavior.
Rule 2.1: No unreachable code.
Rule 2.3: The character sequence 
/*
 shall not be used within a comment.
Rule 2.4: Sections of code should not be commented out.
Rule 2.5: A project should not contain unused macro declarations.
Rule 2.6: Unused type declarations should be removed.
Rule 2.7: Parameters that are not used in the body of a function should be declared as 
(void)
.
Rule 4.2: Trigraphs should not be used.
Rule 5.1: External identifiers shall be distinct.
Rule 5.2: Identifiers declared in the same scope and namespace shall be distinct.
Rule 5.3: An identifier declared in an inner scope shall not hide an identifier declared in an outer scope.
Rule 5.4: Macro identifiers shall be distinct.
Rule 5.5: Identifiers used in the definition and declaration of objects and functions shall be distinct.
Rule 5.6: A typedef name shall be a unique identifier.
Rule 5.7: A tag name shall be a unique identifier.
Rule 5.8: The static storage class specifier shall be used in all declarations of objects and functions that have internal linkage.
Rule 5.9: A mutable identifier shall not be declared at block scope.
Rule 6.1: Bit-fields shall only be defined to be of type 
unsigned int
 or 
signed int
.
Rule 6.2: The value of a composite expression shall not be assigned to an object with wider essential type.
Rule 7.1: Octal constants shall not be used.
Rule 7.2: Real and imaginary numbers shall be represent*/