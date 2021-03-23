/* C Program to Find Maximum Occurring Character in a String */
 
#include <stdio.h>
#include <string.h>
 
int main()
{
  	char str[200], result;
  	int i, len;
  	int max = -1;
  	
  	int freq[256] = {0}; 
 
  	printf("\n Please Enter any String :  ");
  	gets(str);
  	
  	len = strlen(str);
  	
  	for(i = 0; i < len; i++)
  	{
  		freq[str[i]]++; // like  256 ascii table we are incrementing number  if char repeat  
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

