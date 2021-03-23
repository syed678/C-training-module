/* pointer in structure  with dynamic  (getstring)     */

#include <stdio.h>
#include<string.h>
//#include<stdlib.h>
#include"E:\Local\Desktop\update\array\Fun.c"


char* getstring(void);
int CheckName (char *);
struct person
{
   char *name;
   int age;
   float weight;
};

int main()
{
    struct person *personPtr, person1;
    personPtr = &person1;   
	puts("structure example :");

    char arrint[10]={0};
	printf("Enter name: ");
	personPtr->name = getstring();	
	while(  ! CheckName( personPtr->name )  )
	{
		puts("enter Propper name");
		free(personPtr->name);  personPtr->name=NULL;
		personPtr->name = getstring();
	}

/*	LABEL:
		   	printf("Enter name: ");
		    personPtr->name = getstring();
		    if ( ! CheckName( personPtr->name ) ) {
					puts("enter Propper name");
				goto LABEL;
			}
	*/printf("\nEnter age: ");
	personPtr->age = EnterInt();
	printf("Enter weight: ");
    personPtr->weight =EnterFloat();
	printf("Displaying:\n");
  	
	printf("name:\t");
    puts(personPtr->name);
    printf("Age: %d\n", personPtr->age);
    printf("weight: %f", personPtr->weight);

    return 0;
}

 char* getstring(void)
{
	char *p = NULL;
	char index = 0;
	char ch;
	do{
		ch =getchar();
		p = realloc(p,index+1);
		p[index] = ch;
	}while( p[index++]!='\n');

	p[index-1]=0;
	return p; 
	
}
int CheckName (char *p)
{
	int i;
	for(i= 0 ; p[i]; i++ ){
	
		if( !  ( ( isalpha(p[i]) ) || p[i] == ' ' || p[i] == 0) ||  ( p[i] == ' ' && p[i+1] == ' ') ) 
			return 0;
		}
	return 1;
	
	
}


