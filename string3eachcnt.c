/* Count total number of alphabets, digits and special characters in a string*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

static char* getstring(void);
static void CheckData (char *str);
main()
{
	char *str = NULL;
	puts("Enter String :");
	str = getstring();
	puts("enterd string is :");
	puts(str);
	CheckData(str);
	
}

static void CheckData (char *str)
{
	int alphabetscount = 0, digitcount = 0 , specialcharcount = 0; 
	while(*str)
	{
	
		if(isalpha( *str ) )
		 {
			alphabetscount++;
		}
		else if( isdigit( *str ) )
		 { 
			digitcount++;
		}
		else
		{
			specialcharcount++;	
		}
		 str++;   
	
	}	
	printf("No of alphabetes are : %d \t",alphabetscount);
	printf("No of digit are : %d \t",digitcount);
	printf("No of special char are : %d \t",specialcharcount);
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
