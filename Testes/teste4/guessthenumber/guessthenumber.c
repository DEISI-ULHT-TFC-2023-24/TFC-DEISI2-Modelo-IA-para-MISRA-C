#include <stdlib.h>
#include <time.h>

// Function prototypes
extern void display(const char* str);
extern void displayInt(int num);
extern int getInt(void);

int main(void) {
    srand((unsigned int) time(0)); // Cast to unsigned int as srand expects an unsigned int
    int numberToGuess = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    do {
        display("Enter your guess: ");
        guess = getInt(); // Replacing scanf with a custom input function
        attempts++;

        if (guess > numberToGuess) {
            display("Too high! Try again.\n");
        } else if (guess < numberToGuess) {
            display("Too low! Try again.\n");
        } else {
            display("Congratulations! You guessed the number in ");
            displayInt(attempts);
            display(" attempts.\n");
        }
    } while (guess != numberToGuess);

    return 0;
}