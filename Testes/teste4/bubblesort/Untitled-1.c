#include <stdint.h>

// Function prototypes
extern void display(const char* str);
extern void displayInt(int32_t num);

// Function to print an array
void printArray(int32_t array[], int32_t size) {
   for (int32_t i = 0; i < size; i++) {
      displayInt(array[i]);
      display("  ");
   }
   display("\n");
}

// Function to implement bubble sort
void bubbleSort(int32_t array[], int32_t size) {
   for (int32_t step = 0; step < size - 1; ++step) {
      // Run loops two times: one for walking through the array
      // and the other for comparison
      for (int32_t i = 0; i < size - step - 1; ++i) {
         // Swap if greater is at the rear position
         if (array[i] > array[i + 1]) {
            int32_t temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
         }
      }
   }
}

int main() {
   int32_t data[] = {-2, 45, 0, 11, -9};

   int32_t size = sizeof(data) / sizeof(data[0]);

   printf("Unsorted Array\n");
   printArray(data, size);

   bubbleSort(data, size);

   printf("Sorted Array in Ascending Order:\n");
   printArray(data, size);
}