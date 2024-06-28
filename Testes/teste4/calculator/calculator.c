extern double getNum1(void);
extern char getOperator(void);
extern double getNum2(void);
extern void handleDivideByZeroError(void);
extern void handleInvalidOperatorError(void);
extern void displayResult(double result);

int main(void) {
    double num1, num2, result;
    char operator;

    num1 = getNum1();
    operator = getOperator();
    num2 = getNum2();

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
            if(num2 != 0)
            {
                result = num1 / num2;
            }
            else
            {
                /* Handle divide by zero error and return. */
                handleDivideByZeroError();
                return 1;
            }   
            break;
        default:
            /* Handle invalid operator error and return. */
            handleInvalidOperatorError();
            return 1;
    }

    displayResult(result); 

    return 0;
}