/*Here are the MISRA-C:2012 rules from 1 to 23 that have not been applied:

Rule 4.1 - Character encoding: Only character constants and string literals with a valid ASCII representation shall be used.
Rule 8.9 - An object should be defined at block scope if its identifier only appears in a single function.
Rule 11.8 - A cast shall not remove any const or volatile qualification from the type pointed to by a pointer.
Rule 13.7 - Boolean operations whose results are invariant shall not be used.
Rule 21.3 - The memory management functions of shall not be used.
Rule 22.10 - All resources obtained dynamically by means of Standard Library functions shall be explicitly released.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

void displayWord(const char *word, const char *guessedLetters) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (strchr(guessedLetters, word[i]) != NULL) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main(void) {
    char secretWord[MAX_WORD_LENGTH];
    char guessedLetters[MAX_WORD_LENGTH] = "";
    int wordLength;

    printf("Enter a word for someone else to guess: ");
    if(scanf("%19s", secretWord) != 1) {
        // Handle error
        return 1;
    }

    // Convert the word to lowercase for case-insensitive matching
    for (int i = 0; secretWord[i] != '\0'; i++) {
        secretWord[i] = (char)tolower((unsigned char)secretWord[i]);
    }

    wordLength = (int)strlen(secretWord);

    printf("\nWelcome to Guess the Word Game!\n");
    printf("Try to guess the word.\n");

    while (1) {
        displayWord(secretWord, guessedLetters);

        char guess;
        printf("Enter a letter: ");
        if (scanf(" %c", &guess) != 1) {
            // Handle error
            return 1;
        }

        guess = (char)tolower((unsigned char)guess);

        if (strchr(guessedLetters, guess) != NULL) {
            printf("You've already guessed that letter. Try again.\n");
            continue;
        }

        size_t len = strlen(guessedLetters);
        guessedLetters[len] = guess;
        guessedLetters[len + 1] = '\0';

        int correctLettersGuessed = 0;
        for (int i = 0; secretWord[i] != '\0'; i++) {
            if (strchr(guessedLetters, secretWord[i]) != NULL) {
                correctLettersGuessed++;
            }
        }

        if (correctLettersGuessed == wordLength) {
            printf("Congratulations! You guessed the word: %s\n", secretWord);
            break;
        }
    }

    return 0;
}