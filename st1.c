/* pointer to structure         */

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"E:\Local\Desktop\update\array\Fun.c"
struct person
{
   char name[20];
   int age;
   float weight;
};

int main()
{
    puts("structure example :");
	struct person *personPtr, person1;
    personPtr = &person1;   
    char arrint[10]={0};
	printf("Enter name: ");
	gets( personPtr->name);	
	while(  ! CheckName( personPtr->name )  )
	{
		memset( personPtr->name , 0 , 20);
		puts("enter Propper name");
		gets( personPtr->name);	
		
    printf("\nEnter age: ");
	personPtr->age = EnterInt();
	
	printf("Enter weight: ");
    personPtr->weight = EnterFloat();
   
    printf("Displaying:\n");
    printf("name:\t");
    puts(personPtr->name);
    printf("Age: %d\n", personPtr->age);
    printf("weight: %f", personPtr->weight);
    return 0;
}

char CheckName (char *p)
{
	//check name valid or not
	int i;
	for(i= 0 ; p[i]; i++ ){
	
		if( !  ( ( isalpha(p[i]) ) || p[i] == ' ' || p[i] == 0 )  ||  ( p[i] == ' ' && p[i+1] == ' ')) 
			return 0;
		}
		return 1;
	
	
}

