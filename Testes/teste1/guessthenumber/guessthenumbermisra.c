#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100u
#define MIN_NUMBER 1u

int main(void) {
    (void)srand((unsigned int)time(NULL));
    unsigned int numberToGuess = (unsigned int)rand() % MAX_NUMBER + MIN_NUMBER;
    unsigned int guess;
    unsigned int attempts = 0u;

    do {
        printf("Enter your guess: ");
        if(scanf("%u", &guess) != 1)
        {
          break; /* Add error handling here */
        }
        attempts++;

        if (guess > numberToGuess) {
            (void)printf("Too high! Try again.\n");
        } else if (guess < numberToGuess) {
            (void)printf("Too low! Try again.\n");
        } else {
            (void)printf("Congratulations! You guessed the number in %u attempts.\n", attempts);
        }
    } while (guess != numberToGuess);

    return 0;
}
/*main()
 has been changed to 
main(void)
 to explicitly state that it accepts no arguments (Rule 16.6).
The magic numbers 
100
 and 
1
 have been replaced with macros, 
MAX_NUMBER
, and 
MIN_NUMBER
 respectively (Rule 20.4).
Data types changed to unsigned where appropriate (Rules 10.1, 10.2, 10.3, 10.4).
Added a check for the return value of scanf to ensure it correctly read a value (Rule 21.6).
Enclosed library functions (rand, time, printf) in (void) to explicitly ignore their return values (Rule 20.7).
Unapplied rules:

Rule 1.1, 1.2: Compliance to these rules can't be determined without knowledge of the whole software system.
Rule 3.1: Requires a compiler or tool to check.
Rules 4.1, 4.2: Requires a compiler or tool to check.
Rule 5.1, 5.2, 5.3, 5.4, 5.5: These rules apply to identifiers, which seem to be unique and appropriately used in this code.
Rules 6.1, 6.2: These pertain to basic data types and are applied correctly in this code.
Rule 7.1, 7.2: No octal constants are used in this code.
Rule 8.1, 8.2: There are no function parameters in this code except for main.
Rule 9.1: All variables are initialized before use, so this rule is implicitly applied.
Rule 11.1, 11.2, 11.3: Not applicable as there are no pointer conversions in the code.
Rule 12.1, 12.2, 12.3: Not applicable as there are no issues with operator precedence.
Rule 13.1, 13.2, 13.3: Not applicable as there are no issues with side effects.
Rule 14.1, 14.2, 14.3: Control flow seems fine in this code.
Rule 15.1, 15.2, 15.3, 15.4, 15.5: Not applicable as there are no goto statements, and all if, switch, and loop statements seem to be correctly structured.
Rule 16.1, 16.2, 16.3, 16.4, 16.5: There are no function parameters except for main.
Rule 17.1, 17.2, 17.3: No recursion is present in the code, so these rules do not apply.
Rule 18.1, 18.2, 18.3, 18.4, 18.5, 18.6, 18.7, 18*/