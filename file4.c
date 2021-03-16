/*Copy contents of the file to another file.
file3.exe file1name.txt file2name.txt*/

#include<stdio.h>
int main(int argc,char *argv[])
{
	 FILE *fs,*fd;
	 int ch;
	 if(argc!=3)
	 {
	  printf("Invalide numbers of arguments.");
	  return 1;
	 }
	 fs=fopen(argv[1],"r");
	 if(fs==NULL)
	 {
	  printf("Can't find the source file.");
	  return 1;
	 }
	 fd=fopen(argv[2],"w");
	 if(fd==NULL)
	 {
	  printf("Can't open target file.");
	  fclose(fs);
	  return 1;
	 }
	
	 while(1)
	 {
	  ch=fgetc(fs);
	  if (feof(fs)) break;
	  fputc(ch,fd);
	 }
	
	 fclose(fs);
	 fclose(fd);
	 return 0;
}


