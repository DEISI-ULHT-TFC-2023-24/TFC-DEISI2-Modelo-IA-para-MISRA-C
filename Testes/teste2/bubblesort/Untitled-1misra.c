/*The code snippet you provided does conform to many MISRA C:2012 rules, but there are some guidelines not followed:

Rule 4.12 (Advisory): Right hand operands of logical && or || shall be primary-expressions.
In the statement 
for(int step = 0; step < size - 1; ++step)
, the 
size - 1
 is not a primary expression.

Rule 8.13 (Advisory): A pointer should point at a const-qualified type whenever possible.
The arrays in function parameters are not declared as const even when they are not being modified.

Directive 4.6 (Advisory): Typedefs that indicate size and signedness should be used in place of the basic numerical types.
The explicit use of 
int
 instead of a typedef-ed type.

Here's the modified code with these rules applied:*/
#include <stdio.h>
#include <stdbool.h>

typedef int int32_t;
typedef bool boolean_t;

// Function to print an array
void printArray(const int32_t array[], int32_t size) {
   for (int32_t i = 0; i < size; i++) {
      printf("%d  ", array[i]);
   }
   printf("\n");
}

// Function to implement bubble sort
void bubbleSort(int32_t array[], int32_t size) {
   for (int32_t step = 0; (step + 1) < size; ++step) {
      // Run loops two times: one for walking through the array
      // and the other for comparison
      for (int32_t i = 0; (i + 1) < (size - step); ++i) {
         // To sort in descending order, change > to < in this line.
         if (array[i] > array[i + 1]) {
            // Swap if greater is at the rear position
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
   return 0;
}

/*The fixes include:

Replaced 
size - 1
 with 
(step + 1) < size
 and 
size - step - 1
 with 
(i + 1) < (size - step)
 to satisfy MISRA C:2012 Rule 4.12.
Added 
const
 qualifier to array parameter of 
printArray
 function to satisfy MISRA C:2012 Rule 8.13.
Introduced 
typedef
 for 
int
 as 
int32_t
 to satisfy MISRA C:2012 Directive 4.6.
Please note that there could be other rules applicable depending on your company's choice of mandatory rules and related tooling. This analysis is based on a subset of the available rules.*/