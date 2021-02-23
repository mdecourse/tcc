#include <stdio.h>

/**
  - rationale: threads are tied to all kinds of functions that take any number
      and type of parameters.  But all those functions must have the same
      signature.  A solution is for such functions to have one argument, wrap 
      parameters into a struct, and pass a pointer to a struct object as 
      argument to the function.  But structs are data types and we would like
      to be able to pass all kinds of structs into a threaded function.  A
      solution is to make the type of the function argument void*.  Then,
      a cast to void* is used when calling the function, and a cast back to 
      a pointer of the original data type is used in side the function.
      Similarly, the return value of the function could be int, reflecting 
      a status, or void* if a set of values must be returned (as a struct if
      necessary).  This is an example of the above (there no need to employ 
      threads for this demonstration).
  - broader impact: this idea is not just applicable to threads.  In 
      simple_func_3.c it will be seen how doing something similar to this
      allows building a single function that sorts elements of any type
      of array, any way that is desired.  An array on which this sort
      function is applied does not even have to contain numbers.
**/

/* objects of type Data will be used to supply parameters to 'function'      */
typedef struct { int a; int b; char* c; } Data;

/* note: operator -> is used instead of . since struct fields are accessed
   through pointers that need to be dereferenced.                            */ 
void* function (void* data) {
   /* casting data down to (Data*) is necessary to have access to fields a,b,c
      of the struct.  The OS does not think that a type void* has any fields */
   printf("a=%d b=%d c=%s\n",
	  ((Data*)data)->a, ((Data*)data)->b, ((Data*)data)->c);
   return data;
}

int main () {
   char* str = "Hi There Folks";
   /* build the parameter list for 'function'                                */
   Data d1 = { 21, 34, "Hi There Folks" };
   Data d2 = { 12, 43, str };
   /* pass a pointer to an object of type Data but cast as a void* so it
      matches the argument type of 'function'                                */
   function((void*)&d1);
   function((void*)&d2);
}
