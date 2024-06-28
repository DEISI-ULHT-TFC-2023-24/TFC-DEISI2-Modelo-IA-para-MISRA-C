#include <stdio.h>

/* Function to print an array */
static void printArray(const int array[], int size) {
   int i; 
   for (i = 0; i < size; ++i) {
      (void)printf("%d  ", array[i]);
   }
   (void)printf("\n");
}

/* Function to implement bubble sort */
static void bubbleSort(int array[], int size) {
   int step;
   for (step = 0; step < size - 1; ++step) {
      /* Run loops two times: one for walking through the array and the other for comparison. */
      int i;
      for (i = 0; i < size - step - 1; ++i) {
         /* To sort in descending order, change > to < in this line. */
         if (array[i] > array[i + 1]) {
            /* Swap if greater is at the rear position. */
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
         }
      }
   }
}

int main(void) {
   int data[] = {-2, 45, 0, 11, -9};
   int size = sizeof(data) / sizeof(data[0]);

   (void)printf("Unsorted Array\n");
   printArray(data, size);

   bubbleSort(data, size);

   (void)printf("Sorted Array in Ascending Order:\n");
   printArray(data, size);

   return 0;
}

/* 
Added the keyword 
static
 to functions 
printArray
 and 
bubbleSort
 (MISRA-C:2012 Rule 8.7).
The parameter 
array[]
 for the function 
printArray
 is declared as 
const
 because the array 
array[]
 is not modified within this function.
Moved variable declarations to the top of the block (MISRA-C:2012 Directive 4.6).
Added 
(void)
 cast to 
printf
 return value. This is done to indicate that the programmer intentionally disregards the success or failure of calling printf (MISRA-C:2012 Rule 17.7).
Changed 
int main()
 to 
int main(void)
 to comply with MISRA C:2012 Rule 21.6.
 */