/*Display number of “the” stored in the file
file3.exe f1.txt*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
	 FILE *fs;
	 int ch;
	int StrCnt=0;
	int cnt = 0;
	char *pcBuf=NULL;
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
		  if (feof(fs)) {
			break;
			}
		  pcBuf = realloc(pcBuf,cnt+1);//allocating memory to store bytes
		  pcBuf[cnt] = ch;
		  cnt++;
		
		 }
		 char *p;
		 p=pcBuf;
		 while( p  = strstr( p,"the" )){
			 	StrCnt+=1;
			 	p++;
			 	// p += strlen( p );
		  }	
		printf("no of The count for 'the ' is  =  %d\n",StrCnt);
		fclose(fs);
		return 0;
}
