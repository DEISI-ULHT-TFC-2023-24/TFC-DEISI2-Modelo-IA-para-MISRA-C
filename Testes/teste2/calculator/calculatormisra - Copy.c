#include <stdio.h>

int main(void) {
    double num1, num2;
    double result = 0.0;
    char operator;
    int scanResult;

    do {
        printf("Enter first number: ");
        scanResult = scanf("%lf", &num1);
        while(getchar() != '\n'); // clean input buffer
    } while(scanResult != 1);

    do {
        printf("Enter operator (+, -, *, /): ");
        scanResult = scanf(" %c", &operator);
    } while(scanResult != 1 || (operator != '+' && operator != '-' && operator != '*' && operator != '/'));

    do {
        printf("Enter second number: ");
        scanResult = scanf("%lf", &num2);
        while(getchar() != '\n'); // clean input buffer
    } while(scanResult != 1);

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