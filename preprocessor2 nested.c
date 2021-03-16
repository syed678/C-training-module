/* nested macro */

/*A macro calling another macro is called a nested macro*/
//explain in book also
//Program illustrates this concept. In this program, Area is a function of x, and the cost of painting the area is defined as a function of area in the macro definition.

#include<stdio.h> 
 #define Area(x) x*x 
 #define Costpaint(x,y,z) (z*y + Area (x)) 
 
 
 void main() 
 {  
    int A = 8, B= 6, C = 4; 
  
    printf("The area of square= %d\n", Area(A)); 
    printf("Cost of paint= %d\n", Costpaint(A,B,C)); 
 }
