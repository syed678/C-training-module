/*A file name is command line argument. Display the contents of the file where each word will
be displayed on a new line. Display proper message if file does not exist.
 file1.exe filename.txt  */
#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
	 FILE *fp;
	 int ch;
	 char array[20]={0};
	 if(argc!= 2)
	 {
	  printf("invalid command line arguments");
	  return 1;
	 }
	 fp=fopen(argv[1],"r");
	 if( NULL == fp )
	 {
	  printf("Can't find the source file.");
	  return 1;
	 }
	
	
	
	while( fscanf(fp, "%s",array) != EOF ){
	      puts(array);	
    	     memset(array,0,20);
    	}
	fclose(fp);
	 return 0;
}
