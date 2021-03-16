/* 	parameterized macro
Advantages of using a parameterized macro instead of a function*/
#include <stdio.h>

#define SQUARE(N) (N*N)
#define MIN(X, Y)  ((X) < (Y) ? (X) : (Y))
#define SUM(a,b) a+b
int main()
{
	printf("%d\n",SQUARE(10));  //100
	printf("%d\n",MIN(10,5));   //5 
	printf("%d\n",SUM(10,20));  //30
	return 0;
}
