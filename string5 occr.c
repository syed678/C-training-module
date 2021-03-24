/* C Program to Find Maximum Occurring Character in a String */

#include<stdlib.h>
#include <stdio.h>
#include <string.h>
  char* getstring(void);
int main()
{
  	char *str,  result;
  	int i, len;
  	int max = -1;
  	
  	int freq[256] = {0}; 
 
  	printf("\n Please Enter any String :  ");
  	str = getstring();
  	
  	len = strlen(str);
  	
  	for(i = 0; i < len; i++)
  	{
  		if( str[i] != ' '){//avoiding space char
		  freq[str[i]]++; // like  256 ascii table we are incrementing number  if char repeat 
		  }
		   
	}
  		
  	for(i = 0; i < len; i++)
  	{
		
		if( max < freq[str[i]])
		{
			max = freq[str[i]];
			result = str[i];
		}
	}
	printf("\n The Maximum Occurring Character in a Given String = %c and number of occrance id =  %d \n", result,max);
	
  	return 0;
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

