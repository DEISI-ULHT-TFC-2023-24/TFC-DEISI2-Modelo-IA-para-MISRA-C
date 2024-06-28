#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

void displayWord(char *word, char *guessedLetters) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (strchr(guessedLetters, word[i]) != NULL) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    char secretWord[MAX_WORD_LENGTH];
    char guessedLetters[MAX_WORD_LENGTH] = "";
    int wordLength;

    printf("Enter a word for someone else to guess: ");
    scanf("%s", secretWord);

    // Convert the word to lowercase for case-insensitive matching
    for (int i = 0; secretWord[i] != '\0'; i++) {
        secretWord[i] = tolower(secretWord[i]);
    }

    wordLength = strlen(secretWord);

    printf("\nWelcome to Guess the Word Game!\n");
    printf("Try to guess the word.\n");

    while (1) {
        displayWord(secretWord, guessedLetters);

        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        if (strchr(guessedLetters, guess) != NULL) {
            printf("You've already guessed that letter. Try again.\n");
            continue;
        }

        guessedLetters[strlen(guessedLetters)] = tolower(guess);
        guessedLetters[strlen(guessedLetters)] = '\0';

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
