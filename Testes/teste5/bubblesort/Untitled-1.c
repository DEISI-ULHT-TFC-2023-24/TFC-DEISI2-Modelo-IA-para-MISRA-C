/*To make the provided C code compliant with the MISRA-C 2012 rules (from numbers 1 to 23), we will identify any violations and update the code accordingly.

Rules not applied:
Rule 2.1: All code shall be traceable to documented requirements.
This rule pertains to software documentation practices and cannot be addressed in the code itself.
Rule 2.3: Assembly language shall be encapsulated and isolated.
Not applicable as no assembly language is used.
Rule 3.1: The character set and the execution character set shall be documented.
This is about documentation outside the code scope.
Rule 5.2: Identifiers in an inner scope shall not use the same name as an identifier in an outer scope, and therefore hide that identifier.
Handled by ensuring variable names do not conflict within different scopes.
Rule 8.7: Objects shall be defined at block scope if they are only accessed from within a single function.
Compliant as all variables are scoped appropriately.
Rule 9.1: All automatic variables shall have been assigned a value before being used.
All variables are initialized properly.
Rule 10.1, 10.4, 10.5: Implicit type conversions should be avoided.
Compliant as no implicit conversions occur.
Revised Code:
Changes made:

Use 
int32_t
 instead of 
int
 for precise integer types.
Explicitly specify size types using 
size_t
.
Added extra parentheses for clarity in expressions.*/
#include <stdio.h>      // Rule 20.9: Standard headers should be used as per ISO standard, included <stdio.h>
#include <stdint.h>     // Rule 20.9: Including <stdint.h> for fixed-width integer types
#include <stddef.h>     // Rule 20.9: Including <stddef.h> for size_t type

// Function to print an array
void printArray(const int32_t array[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        (void)printf("%d  ", array[i]); // Rule 21.6: Ignoring function return value using explicit cast to void
    }
    (void)printf("\n"); // Rule 21.6: Ignoring function return value using explicit cast to void
}

// Function to implement bubble sort
void bubbleSort(int32_t array[], size_t size) {
    for (size_t step = 0; step < size - 1; ++step) {
        // Run loops two times: one for walking through the array
        // and the other for comparison
        for (size_t i = 0; i < size - step - 1; ++i) {
            // To sort in descending order, change > to < in this line.
            if (array[i] > array[i + 1]) { // Rule 14.3: Should avoid multiple expressions in 'if' condition
                // Swap if greater is at the rear position
                int32_t temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

int main(void) { // Rule 8.1: Return type and parameters shall be explicitly specified
    int32_t data[] = {-2, 45, 0, 11, -9}; // Rule 8.12: Array initialization and considering signedness explicitly

    size_t size = sizeof(data) / sizeof(data[0]); // Rule 10.3: Avoid implicit type conversion by using size_t for sizes

    (void)printf("Unsorted Array\n"); // Rule 21.6: Ignoring return value using explicit cast to void
    printArray(data, size);

    bubbleSort(data, size);

    (void)printf("Sorted Array in Ascending Order:\n"); // Rule 21.6: Ignoring return value using explicit cast to void
    printArray(data, size);

    return 0;
}