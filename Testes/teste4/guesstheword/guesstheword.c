#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

// Prototype for the display functions; these should be implemented per your system's I/O capabilities.
extern void display(const char* str);
extern void displayChar(char ch);
extern void displayNewline(void);
extern int getLine(char* buffer, int maxLength);
extern int getChar(void);

void displayWord(const char *word, const char *guessedLetters);

void displayWord(const char *word, const char *guessedLetters) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (strchr(guessedLetters, word[i]) != NULL) {
            displayChar(word[i]);
        } else {
            displayChar('_');
        }
        displayChar(' ');
    }
    displayNewline();
}



int main(void) {
    char secretWord[MAX_WORD_LENGTH];
    char guessedLetters[MAX_WORD_LENGTH] = "";
    int wordLength;
    int guessedLettersLen = 0;

    display("Enter a word for someone else to guess: ");
    getLine(secretWord, MAX_WORD_LENGTH);

    
    for (int i = 0; secretWord[i] != '\0'; i++) {
        secretWord[i] = tolower(secretWord[i]);
    }

    wordLength = (int)strlen(secretWord);

    display("\nWelcome to Guess the Word Game!\n");


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
