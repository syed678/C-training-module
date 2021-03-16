/*  pointer to pointer*/
/*pointer tompointer stored address of pointer that pointer hol address of element*/
#include <stdio.h>
int main ()
{

   int  var;
   int  *ptr;
   int  **pptr;

   var = 3000;

   /* take the address of var */
   ptr = &var;

   /* take the address of ptr using address of operator & */
   pptr = &ptr;

   /* take the value using pptr */
   printf("\nValue of var = %d", var );  //3000
   printf("\tValue available at *ptr = %d", *ptr ); //3000
   printf("\nValue available at *pptr = %d \t and Address for ptr is  = %d", *pptr,ptr); // same address for both
   printf("\nValue available at **pptr = %d\n", **pptr); // 3000

   return 0;
}
