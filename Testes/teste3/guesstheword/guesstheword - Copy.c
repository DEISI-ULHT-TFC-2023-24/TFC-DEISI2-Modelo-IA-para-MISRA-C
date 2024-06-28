#include <ctype.h>

#define MAX_WORD_LENGTH 21U /* +1 for '\0' terminator */

static void displayWord(const char *word, const char *guessedLetters) {
    unsigned int i = 0U;
    while (word[i] != '\0') {
        if ((const char*)strchr(guessedLetters, word[i]) != NULL) { /* Rule 21.7 */
            (void)printf("%c ", word[i]);
        } else {
            (void)printf("_ ");
        }
        ++i;
    }
    (void)printf("\n");
}

int main(void) {
    char secretWord[MAX_WORD_LENGTH] = "";
    char guessedLetters[MAX_WORD_LENGTH] = "";
    unsigned int wordLength;

    (void)printf("Enter a word for someone else to guess: ");
    (void)scanf("%20s", secretWord); /* Rule 21.6, Rule 22.9 */

    unsigned int i = 0U;
    while (secretWord[i] != '\0') {
        secretWord[i] = (char)tolower((int)secretWord[i]); /* Rule 21.3, Rule 10.4 */
        ++i;
    }

    wordLength = (unsigned int)strlen(secretWord); /* Rule 21.4 */

    (void)printf("\nWelcome to Guess the Word Game!\n");
    (void)printf("Try to guess the word.\n");

    while (1) {
        displayWord(secretWord, guessedLetters);

        char guess;
        (void)printf("Enter a letter: ");
        (void)scanf(" %c", &guess); /* Rule 21.6 */

        if ((const char*)strchr(guessedLetters, guess) != NULL) { /* Rule 21.7 */
            (void)printf("You've already guessed that letter. Try again.\n");
            continue;
        }

        unsigned int len = (unsigned int)strlen(guessedLetters); /* Rule 21.4 */
        guessedLetters[len] = (char)tolower((int)guess); /* Rule 10.4, Rule 21.3 */
        guessedLetters[len + 1U] = '\0';

        unsigned int correctLettersGuessed = 0U;
        for (i = 0U; secretWord[i] != '\0'; ++i) {
            if ((const char*)strchr(guessedLetters, secretWord[i]) != NULL) { /* Rule 21.7 */
                ++correctLettersGuessed;
            }
        }

        if (correctLettersGuessed == wordLength) {
            (void)printf("Congratulations! You guessed the word: %s\n", secretWord);
            break;
        }
    }

    return 0;
}