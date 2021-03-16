#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static char* getstring(void);
static void StrRev(char *);
main()
{
	char *str = NULL;
	puts("Enter String :");
	str = getstring();
	puts("str before reverse :");
	puts(str);
	StrRev(str);
	puts("str After reverse :");
	puts(str);
}


static void StrRev(char *str)
{
 
 int i,j;
 char temp ;
 for(i=0,j=strlen(str)-1;i<=j;i++,j--){
 
	 temp = str[i];
	 str[i]=str[j];
	 str[j] = temp;
 }
 
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
