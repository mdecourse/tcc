#include <stdio.h>

/** 
  - understand what a pointer is in relation to variables that have values
    needed for some meaningful computation 
  - nothing is being done with the pointers yet other than showing that
    their values are memory addresses
**/
int main () {
   int a;     /* real space to do something with */
   int* b;    /* pointer to real space to do something with */
   int** c;   /* pointer to a pointer to real space to do something with */

   a = 101;   /* real space gets value */
   b = &a;    /* pointer to the real space - indirect reference */
   c = &b;    /* pointer to pointer to pointer */
   /* dereferencing pointers, show contents of the pointers */ 
   printf("a:%d b:%d c:%d\n",a,*b,**c);
   printf("a:%d b:%ld c:%ld\n",a,(unsigned long)b,(unsigned long)c);
}

/* Note: &&a makes no sense and is not allowed */
