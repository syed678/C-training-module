/*A file name is command line argument. Display the contents of the file where each word will
be displayed on a new line. Display proper message if file does not exist.
 file1.exe filename.txt  */
#include<stdio.h>
int main(int argc,char *argv[])
{
	 FILE *fs;
	 int ch;
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
	  printf("\n%c",ch);
	  
	 }
	
	 fclose(fs);
	 
	 return 0;
}
