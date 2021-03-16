/*  Array of Pointers(Pointer Array)*/

#include<stdio.h>
#include<string.h>
int factorial(int );

int main()
{
    int i = 1, *ip = &i;
	//array of pointers
    char *sports[] = {
                         "Akola",
                         "Amravati",
                         "takli",
                         "Balapur",
                         "shivni"
                     };

    for(i = 0; i < 5; i++,printf("\n"))
    {
        printf("String = %10s", sports[i] );
        printf("\tAddress of string literal = %u\t", sports+i);
       
        
    }
	printf("In all Addresses Diffrence will be size  of Pointer  = %d \n",sizeof(char*));
    // signal to operating system program ran fine
    return 0;
}
