/*  Function returning pointer and function pointer examples */

#include<stdio.h>
#include<stdlib.h>
static char* getstring(void);

int main()
{
	char *name = NULL;	
	//this will return har pointer
	
	LABEL2:	//check all entered values are alphabates or not
		    printf("\nEnter Name : "); 
			//getchar();
			puts("Enter name ");
			name = getstring(); 
			if ( ! CheckName( name) ) {
					puts("enter Propper name");
				goto LABEL2;
			}
	puts(name);
	free(name);
	name = NULL;
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
