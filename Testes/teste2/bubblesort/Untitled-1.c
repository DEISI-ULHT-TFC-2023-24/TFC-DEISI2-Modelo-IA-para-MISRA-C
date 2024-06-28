#include <stdio.h>

// Function to print an array
void printArray(int array[], int size) {
   for (int i = 0; i < size; i++) {
      printf("%d  ", array[i]);
   }
   printf("\n");
}

// Function to implement bubble sort
void bubbleSort(int array[], int size) {
   for (int step = 0; step < size - 1; ++step) {
      // Run loops two times: one for walking through the array
      // and the other for comparison
      for (int i = 0; i < size - step - 1; ++i) {
         // To sort in descending order, change > to < in this line.
         if (array[i] > array[i + 1]) {
            // Swap if greater is at the rear position
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
         }
      }
   }
}

int main() {
   int data[] = {-2, 45, 0, 11, -9};

   int size = sizeof(data) / sizeof(data[0]);

   printf("Unsorted Array\n");
   printArray(data, size);

   bubbleSort(data, size);

   printf("Sorted Array in Ascending Order:\n");
   printArray(data, size);
}