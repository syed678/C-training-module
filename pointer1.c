/*   Pointers and 1D/2D arrays (2d aarray is in next file -> pointer12) */

#include <stdio.h>
#include<string.h>
static int CheckarrtoInt(char*);

int main()
{
  int var = 5;		
  int* p= &var;
  int values[5];
  int i = 0;
  	char arrint[10]={0};
  printf("var: %d\n", var);
  printf("address of var: %p  .\t. %p ", &var,p); 
  printf("\ndata of var: %d",*p); 
    
 
 //from here 1d array example
	printf("\nEnter 5 integers: ");

  // taking input and storing it in an array
  for( i = 0; i < 5; ++i) {
   	Label1:
			printf("\nEnter number : "); 
		    scanf("%s",arrint);
			if(  CheckarrtoInt( arrint )){
				values[i] = atoi( arrint );
			}
			else{
				puts("enter valid no");
				memset(arrint,0,10);
				goto Label1;
			}

	// scanf("%d", &values[i]);
  }

  printf("\nDisplaying integers: ");

  // printing elements of an array
  for( i = 0; i < 5; ++i) {
     printf("\n%d", values[i]);
  }
  return 0;
}



static int CheckarrtoInt(char*p)
{
	//checking int or other data?
	//if int return 1
	int i;
	for(i=0;i<10;i++){
		if(  ( isdigit(p[i]) || p[i] == 0) )
			continue;
			else
			 return 0;
			
	}	
	return 1;
}
