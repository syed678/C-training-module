/*  in string count numberof words*/
#include<stdio.h>
#include<stdlib.h>
char* getstring(void);
char CheckString (char *p);
main()
{
	char *str = NULL,*p;
//	char *str = "     hello my frd",*p;
	char arr[20];
	int wordcnt = 0;
	puts("Enter String :");
	str = getstring();
	while(  ! CheckString( str )  )
	{	//validation
		puts("enter Propper String of Alphabate");
		free(str); 
		str=NULL;
		str = getstring();
	}
	
	
	puts("string is :");
	puts(str);
	p=str;
		while( *p == ' ' || *p== '\n'){
		p++; 
		//puts("check");	
	}
		while(*p != 0 ){
			while( isalpha(*p) ){
				p++; // If alpha loop up to space
			}
			while (  isspace(*p) &&  isspace(*(p+1) ) )  {
				p++;	
			}
			wordcnt++;	
			p++;
	}
	printf("No of word count is : %d ", wordcnt);
	return;
	
	///////////////////////////////
	/*
	
		
	
	while( *(p+1) == ' ' || *(p+1) == '\n')
		p++;// check if space or new line skip
	
	while( sscanf( p,"%s", arr ) == 1 ){
	while(*(p+1) == ' ' || *(p+1) == '\n')
		p++;
	wordcnt++;
	puts(arr);
	p += (strlen(arr)+1);
	memset(arr,0,20);
	}*/
	

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


	p[index-1] = 0;
	p[index] = 0;
	return p; 
	
}

char CheckString (char *p)
{
	int i;
	for(i= 0 ; p[i]; i++ ){
		if( isspace(p[i]) || isalpha(p[i]) ){
			continue;
		}
		else{
				return 0;
		}
	}
	return 1;
}

