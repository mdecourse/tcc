#include <stdio.h>
#include <string.h>

/**
  -  repeat of 'simple_function_1.c' except that the value of a parameter is 
     changed inside 'function' and the effect of the change is noticed 
     after 'function' terminates.  The fact that 'data' is returned is not
     important to this example - I just wanted to return something that is
     compatible with void*
**/
typedef struct { char* a; int b; int c; } Data;

void* function (void* data) {
   printf("a=%s b=%d c=%d\n",
	  ((Data*)data)->a, ((Data*)data)->b, ((Data*)data)->c);
   ((Data*)data)->b = 1001;
   return data;
}

int main () {
   Data* ret;
   char* str = "Hi There Folks";
   Data d1 = { "Hi There Folks", 21, 34 };
   ret = (Data*)function(&d1);
   printf("value=%d\n",ret->b);
}
