#include <stdint.h> /* for int32_t */
#include <stdbool.h> /* for bool */
#include <stdio.h>   /* for printf function */
#include <stdlib.h> /* for exit function */

/*
 * This program sorts an array of integers in ascending order using bubble sort.
 */

/* Function Prototypes */
void printArray(const int32_t array[], size_t size); /* Prints elements of the array */
void bubbleSort(int32_t array[], size_t size); /* Implements the bubble sort algorithm */

/*
 * Print Array Function
 * Takes an integer array and its size as input.
 * Prints each element of the array, followed by a newline.
 */
void printArray(const int32_t array[], size_t size) {
   for (size_t i = 0; i < size; i++) {
      if(printf("%d  ", array[i]) < 0){
         /* Handle Error and Exit */
         perror("printf error");
         exit(EXIT_FAILURE);
      }
   }
   if(printf("\n") < 0){
      /* Handle Error and Exit */
      perror("printf error");
      exit(EXIT_FAILURE);
   }
}

/*
 * Bubble Sort Function
 * Takes an integer array and its size as input.
 * Sorts the array in ascending order using bubble sort.
 */
void bubbleSort(int32_t array[], size_t size) {
   for (size_t step = 0; (step + 1) < size; ++step) {
      for (size_t i = 0; (i + 1) < (size - step); ++i) {
         if (array[i] > array[i + 1]) {
            int32_t temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
         }
      }
   }
}

/*
 * Main Function
 * Defines an array of integers and its size, prints the unsorted array,
 * sorts the array using bubble sort, then prints the sorted array.
 */
int main(void) {
   int32_t data[] = {-2, 45, 0, 11, -9};
   size_t size = sizeof(data) / sizeof(data[0]);

   if(printf("Unsorted Array\n") < 0){
      /* Handle Error and Exit */
      perror("printf error");
      exit(EXIT_FAILURE);
   }
   printArray(data, size);

   bubbleSort(data, size);

   if(printf("Sorted Array in Ascending Order:\n") < 0){
      /* Handle Error and Exit */
      perror("printf error");
      exit(EXIT_FAILURE);
   }
   printArray(data, size);

   return 0;
}