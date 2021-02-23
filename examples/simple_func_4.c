#include <stdlib.h>
#include <stdio.h>

/**
  - this is a repeat of simple_func_3.c except that the elements of the array 
    to be sorted are pointers to Cable objects.
**/

typedef struct { int city1, city2, cost; } Cable;

/* This is the user-defined cost compare function for qsort's 4th argument */
/* a cable with less cost moves toward the front of the array              */
/* (that is, qsort swaps it with the cable of higher cost, if necessary)   */
/* since array elements are pointers, x and y need to be dereferenced      */
/* twice to access the actual Cable objects to be sorted                   */
int costCompare (const void* x, const void* y) {
   if ((*((Cable**)x))->cost < ((*(Cable**)y))->cost) return -1;
   if ((*((Cable**)x))->cost > ((*(Cable**)y))->cost) return 1;
   return 0;
}

int main() {
   int i;
   Cable* cables[10];   /* an array of 10 pointers to Cable objects        */

   for (i=0 ; i < 10 ; i++) {   /* array elements are assigned values      */
      cables[i] = (Cable*)malloc(sizeof(Cable));
      cables[i]->city1 = i;
      cables[i]->city2 = i+1;
      cables[i]->cost = rand() % 200;  /* costs are assigned randomly      */
   }

   /* Sort a list of cables on increasing cost                             */
   /* Builtin function 'sizeof' returns the # bytes of memory the type,    */
   /* stated as its argument, actually takes up.                            */
   qsort(cables, 10, sizeof(Cable*), costCompare);

   /* Print the sorted array 
      (operator -> is used because elements are pointers to objects        */
   for (i=0 ; i < 10 ; i++) 
      printf("[%d,%d,%d]\n",cables[i]->city1, cables[i]->city2, cables[i]->cost);
}
