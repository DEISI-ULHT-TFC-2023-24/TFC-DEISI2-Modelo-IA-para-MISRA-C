#include <time.h>

#define MAX_NUMBER 100U
#define MIN_NUMBER 1U

int main(void) /* Rule 16.1 (required): Functions shall not be defined with a variable number of arguments */
{
    unsigned int numberToGuess;
    unsigned int guess;
    unsigned int attempts = 0U;
    int statusGuess;

    srand((unsigned int) time(NULL)); /* Rule 21.5 (required): The library functions abort, exit, getenv and system of <stdlib.h> shall not be used */

    numberToGuess = ((unsigned int)rand() % MAX_NUMBER) + MIN_NUMBER; /* Rule 21.6 (required): The Standard Library input/output functions shall not be used */

    do
    {
        (void)printf("Enter your guess: "); /* Rule 21.6 (required) */
        statusGuess = scanf("%u", &guess); /* Rule 21.6 (required) */

        if(statusGuess == 1)
        {
            attempts++;

            if (guess > numberToGuess)
            {
                (void)printf("Too high! Try again.\n");
            }
            else if (guess < numberToGuess)
            {
                (void)printf("Too low! Try again.\n");
            }
            else
            {
                (void)printf("Congratulations! You guessed the number in %u attempts.\n", attempts);
            }
        }
        else
        {
            (void)printf("Error: Invalid inputs\n");
            return 1;
        }
    }
    while (guess != numberToGuess);

    return 0; /* Rule 2.2 (required): There shall be no dead code */
}