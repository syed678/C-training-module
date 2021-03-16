//count number of vowel in file on command line file2.exe filename.txt
#include<stdio.h>
static int IsVowel(char x);
int main(int argc,char *argv[])
{
	 FILE *fs;
	 int ch;
	 int VowelCnt = 0;
	 if(argc!= 2)
	 {
	  printf("invalid command line arguments");
	  return 1;
	 }
	 fs=fopen(argv[1],"r");
	 if(fs==NULL)
	 {
	  printf("Can't find the source file.");
	  return 1;
	 }
	
	
	 while(1)
	 {
	  ch=fgetc(fs);
	  if (feof(fs)) break;
	  if( IsVowel(ch) )
	  		VowelCnt++;
	 }
	 printf("\nNumberof Vowel in file : %d",VowelCnt);
	 fclose(fs);
	 
	 return 0;
}//

static int IsVowel(char x)
{
	 if (x == 'a' || x == 'e' || x == 'i' || 
        x == 'o' || x == 'u' || x == 'A' || 
        x == 'E' || x == 'I' || x == 'O' || x == 'U'){
        	return 1; 
		}else{
			return 0;
		}
	
}
