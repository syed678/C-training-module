#include<stdio.h>
#include"E:\Local\Desktop\update\array\Fun.c"
char* getstring(void);
void StrRev(char *);
main()
{
	char *str = NULL;
	puts("Enter String :");
	str = getstring();
	/*
	//validation part
	while(  ! CheckName( str )  )
	{
		puts("enter Propper name");
		free(str); 
		str=NULL;
		str = getstring();
	}
	*/

	puts("str before reverse :");
	puts(str);
	StrRev(str);
	puts("str After reverse :");
	puts(str);
	free(str); 
	str=NULL;
}
void StrRev(char *str)
{
 
	 int i,j;
	 char temp ;
	 for(i=0,j=strlen(str)-1;i<=j;i++,j--){
		 temp = str[i];
		 str[i]=str[j];
		 str[j] = temp;
 	 }
 
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
