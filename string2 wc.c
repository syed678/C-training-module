/*  in string count numberof words*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static char* getstring(void);

main()
{
	char *str = NULL,*p;
	char arr[20];
	int wordcnt = 0;
	puts("Enter String :");
	str = getstring();

	puts("string is :");
	puts(str);
	p=str;
	while( *(p+1) == ' ' || *(p+1) == '\n')
		p++;// check if space or new line skip
	while( sscanf( p,"%s", arr ) == 1 ){
	while(*(p+1) == ' ' || *(p+1) == '\n')
		p++;
	wordcnt++;
	puts(arr);
	p += (strlen(arr)+1);
	memset(arr,0,20);
	}
	printf("No of word count is : %d ", wordcnt);
	return;

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


	p[index-1] = 0;
	return p; 
	
}
