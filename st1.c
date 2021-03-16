/* pointer to structure         */

#include <stdio.h>
#include<string.h>
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
	LABEL:	memset(personPtr->name,0,20);
		   	printf("Enter name: ");
		   gets( personPtr->name);
		   // scanf("%s", personPtr->name);
				
			if ( ! CheckName( personPtr->name ) ) {
					puts("enter Propper name");
				goto LABEL;
			}
  
    
    LAB: printf("\nEnter age: ");
	   // scanf("%s",arrint);
		gets(arrint);
		if(  CheckarrtoInt( arrint )){
			personPtr->age = atoi( arrint );
		}
		else{
			puts("enter valid no");
			memset(arrint,0,10);
			goto LAB;
		}
    

    printf("Enter weight: ");
    scanf("%f", &personPtr->weight);
    
    
    

    printf("Displaying:\n");
   printf("name:\t");
   puts(personPtr->name);
    printf("Age: %d\n", personPtr->age);
    printf("weight: %f", personPtr->weight);

    return 0;
}

int CheckarrtoInt(char*p)
{	//check int value valid or not
	int i;
	for(i=0;i<10;i++){
		if(  ( isdigit(p[i]) || p[i] == 0) )
			continue;
			else
			 return 0;
			
	}	
	return 1;
}

int CheckName (char *p)
{
	//check name valid or not
	int i;
	for(i= 0 ; p[i]; i++ ){
	
	//	if( !  () ( isalpha(p[i]) ) || p[i] == ' ' || p[i] == 0)
		if( !  ( ( isalpha(p[i]) ) || p[i] == ' ' || p[i] == 0) ) 
			return 0;
		}
		return 1;
	
	
}

