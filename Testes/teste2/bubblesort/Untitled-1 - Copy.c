#include <stdio.h>

typedef int MyInt;
typedef unsigned long MySize;

// Function to print an array
void printArray(const MyInt array[], MySize size) {
   for (MySize i = 0; i < size; i++) {
      if(printf("%d  ", array[i]) < 0){
          // Handle the error
      };
   }
   if(printf("\n") < 0){
       // Handle the error
   };
}

// Function to implement bubble sort
void bubbleSort(MyInt array[], MySize size) {
   for (MySize step = 0; step < (size -1); ++step) {
      // Run loops two times: one for walking through the array
      // and the other for comparison
      for (MySize i = 0 ; i < ((size - step) - 1); ++i) {
         // To sort in descending order, change > to < in this line.
         if (array[i] > array[i + 1]) {
            // Swap if greater is at the rear position
            MyInt temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
         }
      }
   }
}

int main() {
   MyInt data[] = {-2, 45, 0, 11, -9};
   MySize size = sizeof(data) / sizeof(data[0]);

   if(printf("Unsorted Array\n") < 0){
       // Handle the error
   };
   printArray(data, size);

   bubbleSort(data, size);

   if(printf("Sorted Array in Ascending Order:\n") < 0){
       // Handle the error
   };
   printArray(data, size);
   return 0;
}