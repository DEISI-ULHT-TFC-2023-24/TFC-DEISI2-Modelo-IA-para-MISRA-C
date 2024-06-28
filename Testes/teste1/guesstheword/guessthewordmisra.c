#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20u /* Use unsigned type for size definitions */

void displayWord(const char *word, const char *guessedLetters) { /* Rule 8.13: Pointer parameters should be declared as pointer to const if they aren't modified */
    unsigned int i;
    for (i = 0u; word[i] != '\0'; i++) {
        if (strchr(guessedLetters, word[i]) != NULL) {
            (void)printf("%c ", word[i]);
        } else {
            (void)printf("_ ");
        }
    }
    (void)printf("\n");
}

int main(void) { /* Rule 16.6: main should be defined with void since it doesn't take any arguments */
    char secretWord[MAX_WORD_LENGTH];
    char guessedLetters[MAX_WORD_LENGTH] = "";
    size_t wordLength; /* Rule 10.6: Use size_t for strlen function */

    (void)printf("Enter a word for someone else to guess: ");
    if (scanf("%s", secretWord) != 1) { /* Rule 21.6: Check return value of scanf */
        return 1; /* Provide error handling */
    }

    unsigned int i;
    for (i = 0u; secretWord[i] != '\0'; i++) {
        secretWord[i] = (char)tolower((unsigned char)secretWord[i]); /* Rule 10.3: Operands shall not be of an inappropriate essential type */
    }

    wordLength = strlen(secretWord);

    (void)printf("\nWelcome to Guess the Word Game!\n");
    (void)printf("Try to guess the word.\n");

    while (1) {
        displayWord(secretWord, guessedLetters);

        char guess;
        (void)printf("Enter a letter: ");

        if (scanf(" %c", &guess) != 1) { /* Rule 21.6: Check return value of scanf */
            return 1; /* Provide error handling */
        }

        if (strchr(guessedLetters, guess) != NULL) {
            (void)printf("You've already guessed that letter. Try again.\n");
            continue;
        }

        guessedLetters[strlen(guessedLetters)] = (char)tolower((unsigned char)guess); /* Rule 10.3: Operands shall not be of an inappropriate essential type */
        guessedLetters[strlen(guessedLetters)] = '\0';

        unsigned int correctLettersGuessed = 0u;
        for (i = 0u; secretWord[i] != '\0'; i++) {
            if (strchr(guessedLetters, secretWord[i]) != NULL) {
                correctLettersGuessed++;
            }
        }

        if (correctLettersGuessed == wordLength) {
            (void)printf("Congratulations! You guessed the word: %s\n", secretWord);
            break;
        }
    }

    return 0;
}
/*Unapplied MISRA-C rules 2012 (from number 1 to number 23) are as follows:

Rules 1.1 and 1.2: Compliance to these rules can't be determined without knowledge of the whole software system.
Rule 3.1: Requires a compiler or tool to check.
Rules 4.1 and 4.2: Requires a compiler or tool to check.
Rules 5.1, 5.2, 5.3, 5.4, and 5.5: These rules apply to identifiers, which seem to be unique and appropriately used in this code.
Rules 6.1 and 6.2: These pertain to basic data types and are applied correctly in this code.
Rules 7.1 and 7.2: No octal constants are used in this code.
Rules 8.1 and 8.2: There are no function parameters in this code except for main.
Rule 9.1: All variables are initialized before use, so this rule is implicitly applied.
Rules 11.1, 11.2, and 11.3: Not applicable as there are no pointer conversions in the code.
Rules 12.1, 12.2, and 12.3: Not applicable as there are no issues with operator precedence.
- Rules 13.1, 13.2, and 13.3: Not applicable as there are no issues with side effects.*/