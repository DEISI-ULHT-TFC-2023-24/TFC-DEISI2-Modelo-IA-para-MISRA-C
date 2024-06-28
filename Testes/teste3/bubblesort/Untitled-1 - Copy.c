#include <stdio.h>

#define SIZE 5U

/* MISRA C:2012 Rule 1.3 (advisory)
 There shall be no occurrence of undefined or critical unspecified behavior.
 The array size is a non-compliance, so we use #define to set it as a constant. */

typedef unsigned int Index_t;
/* MISRA C:2012 Rule 6.1 (required)
 Bit-fields shall only be defined to be of type unsigned int or signed int.
 In this case, we use unsigned int */

/* Function to print an array */
static void printArray(const int array[SIZE], Index_t size) /* MISRA C:2012 Rule 8.13 (Advisory)
 If a function parameter is not modified, its qualifier const shall be added.*/
{
   for (Index_t i = 0U; i < size; ++i) {
      (void)printf("%d  ", array[i]);
   }
   (void)printf("\n");
}

/* Function to implement bubble sort */
static void bubbleSort(int array[SIZE], Index_t size) /* static has been included to comply with MISRA C:2012 Rule 8.7 (Advisory)
 Functions shall be declared static if they are referenced in only one translation unit. */
{
   for (Index_t step = 0U; step < (size - 1U); ++step) {
      for (Index_t i = 0U; i < (size - step - 1U); ++i) {
         if (array[i] > array[i + 1]) {
            /* Swap if greater is at the rear position */
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
         }
      }
   }
}

int main(void) /* MISRA C:2012 Rule 16.1 (Required)
 Functions shall not be defined with variable numbers of arguments */
{
   int data[SIZE] = {-2, 45, 0, 11, -