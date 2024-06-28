/*Analysis of MISRA-C 2012 Rule Violations:
Rule 1.1: No rule violations related to syntax.
Rule 1.2: No rule violations related to undefined behavior in this context.
Rule 2.1: Dead code is not present.
Rule 2.2: No unused values.
Rule 2.3: No unreachable code.
Rule 2.4: Non-volatile objects are not used in a signal handler.
Rule 2.5: Inline assembly is not used.
Rule 2.6: Typedefs are not defined but also not necessary for compliance.
Rule 3.1: No use of trigraphs.
Rule 4.1: No use of octal constants.
Rule 4.2: No character constants with more than one character.
Rule 5.1: No use of any identifiers from the standard library.
Rule 5.2: Identifiers are distinct.
Rule 5.3: No declarations in more than one namespace.
Rule 5.4: No object or function identifier reuse.
Rule 5.5: Macros don't appear.
Rule 5.6: No typedef reuse.
Rule 5.7: Function-like macros not present.
Rule 5.8: No tag reuse.
Rule 5.9: No external linkage conflict.
Rule 5.10: No identical typedef names.
Rule 5.11: No enum reuse.
Rule 6.1: Boolean type not used in controlling expressions.
Specific Corrections Needed:
Rule 7.2: Critical header inclusion should be protected against multiple inclusions.
Rule 8.1: Functions and variables should have prototypes and declarations respectively.
Rule 8.3: Objects should be declared with external linkage only once.
Rule 8.9: Variables should be declared at block scope if only used within one function.
Rule 9.1: Initialization of automatic variables.
Rule 14.3: Controlling expression of 
if
 statements must evaluate to 
boolean
.
Rule 14.4: The controlling expression of an 
if
 statement and iteration-statement shall have essentially Boolean type.
Rule 15.7: All 
if...else if
 constructs shall be terminated with an else statement even if it does nothing.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int guess = 0;
    int attempts = 0;
    int numberToGuess;

    /* Initialize random seed */
    srand((unsigned int)time(NULL));

    /* Generate the number to guess */
    numberToGuess = (rand() % 100) + 1;

    do {
        printf("Enter your guess: ");

        /* Validate scanf return */
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter an integer.\n");

            /* Clear stdin buffer */
            while (getchar() != '\n') {
                /* Discard input */
            }
            continue;
        }

        attempts++;

        if (guess > numberToGuess) {
            printf("Too high! Try again.\n");
        } else if (guess < numberToGuess) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != numberToGuess);

    return 0;
}