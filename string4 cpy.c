/*copy one string to other*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

static char* getstring(void);
char *my_strcpy(char *destination, char *source);

main()
{
	char *str1 = NULL,*str2=NULL;
	puts("Enter 1st String :");
	str1 = getstring();
	
	puts("Enter 2nd String :");
	str2 = getstring();
	
	str1 = realloc(str1,strlen(str2) +1);
	my_strcpy( str1 , str2 );
	puts(" now string is : ");
	puts(str1);
	
}

char *my_strcpy(char *destination, char *source)
{
    char *start = destination;

    while(*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0'; // add '\0' at the end
    return start;
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
