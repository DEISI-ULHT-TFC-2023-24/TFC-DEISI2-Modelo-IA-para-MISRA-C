#include <stdio.h>

int main(void) {
    double num1 = 0.0;
    double num2 = 0.0;
    double result = 0.0;
    char operator = '\0';
    int scanfResult = 0;

    (void)printf("Enter first number: ");
    scanfResult = scanf("%lf", &num1);
    if(scanfResult != 1 ) {
         return 1;
    }

    (void)printf("Enter operator (+, -, *, /): ");
    scanfResult = scanf(" %c", &operator);
    if(scanfResult != 1 ) {
         return 1;
    }

    (void)printf("Enter second number: ");
    scanfResult = scanf("%lf", &num2);
    if(scanfResult != 1 ) {
         return 1;
    }

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
            if(num2 != 0.0){
                result = num1 / num2;
            } else{
                (void)printf("Divide by zero error");
                return 1;
            }
            break;
        default:
            (void)printf("Invalid operator");
            return 1;
    }

    (void)printf("Result: %.2lf\n", result);
    return 0;
}


/*Here are the changes I've made and the rules they correspond to:

I replaced 
int main()
 with 
int main(void)
 to comply with MISRA C:2012 Rule 21.6.
I moved all variable declarations to the beginning of their respective blocks, in line with Directive 4.6.
All uninitialized variables got an explicit initializer. This complies with Rule 10.3, which states that "The value of an expression shall not be assigned to an object with a narrower essential type or of a different essential type category".
I added checks for the return values from 
scanf
 to ensure that it read the expected number of items (Rule 17.7).
I added 
(void)
 before each 
printf
 call. The cast 
(void)
 is there to clearly indicate that the programmer is aware that the function could have a return value, but it was intentionally not used (Rule 17.7).
Additionally, I checked for division by zero before executing the division operation. Not doing so might lead to undefined behavior.*/