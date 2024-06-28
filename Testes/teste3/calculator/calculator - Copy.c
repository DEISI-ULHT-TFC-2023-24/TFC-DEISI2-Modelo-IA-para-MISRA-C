#include <stdio.h>

int main(void) /* Rule 16.1 (required): Functions shall not be defined with a variable number of arguments */
{
   double num1 = 0.0;
   double num2 = 0.0;
   double result = 0.0;
   char operator = '\0';
   int statusNum1 = 0;
   int statusOperator = 0;
   int statusNum2 = 0;

   (void)printf("Enter first number: ");
   statusNum1 = scanf("%lf", &num1); /* Rule 21.6 (required): The Standard Library input/output functions shall not be used */

   (void)printf("Enter operator (+, -, *, /): ");
   statusOperator = scanf(" %c", &operator); /* Rule 21.6 (required) */

   (void)printf("Enter second number: ");
   statusNum2 = scanf("%lf", &num2); /* Rule 21.6 (required) */

   if ((statusNum1 == 1) && (statusOperator == 1) && (statusNum2 == 1)) /* Check all inputs were received correctly */
   {
      switch (operator)
      {
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
            if (num2 != 0.0) /* Rule 10.4 (required): Both operands of an operator in which the usual arithmetic conversions are performed shall have the same essential type category */
            {
               result = num1 / num2;
            }
            else
            {
               (void)printf("Error: Division by zero\n");
               return 1;
            }
            break;
         default:
            (void)printf("Invalid operator\n");
            return 1;
      }

      (void)printf("Result: %.2lf\n", result);
   }
   else
   {
      (void)printf("Error: Invalid inputs\n");
      return 1;
   }

   return 0; /* Rule 2.2 (required): There shall be no dead code */
}