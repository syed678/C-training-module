/* pointer in structure  with dynamic  (getstring)     */

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

static char* getstring(void);

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
//	personPtr->name = calloc(1 , 20);
//	strcpy(personPtr->name,"aanand");
   
  
 /*   
	printf("Enter name: ");
    personPtr->name = getstring();
	
    printf("Enter age: ");
    scanf("%d", &personPtr->age);

    printf("Enter weight: ");
    scanf("%f", &personPtr->weight);

*/
	puts("structure example :");

    char arrint[10]={0};
	LABEL:
		   	printf("Enter name: ");
		    personPtr->name = getstring();
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

static char* getstring(void)
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



int CheckarrtoInt(char*p)
{
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
	int i;
	for(i= 0 ; p[i]; i++ ){
	
	//	if( !  () ( isalpha(p[i]) ) || p[i] == ' ' || p[i] == 0)
		if( !  ( ( isalpha(p[i]) ) || p[i] == ' ' || p[i] == 0) ) 
			return 0;
		}
		return 1;
	
	
}


