/*Copy contents of the file to another file.
file4cpy.exe f1.txt f2.txt*/
// now open in apend mode
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
	 if(fs==NULL){
	  printf("source file not found.");
	  return 1;
	 }
	 fd=fopen(argv[2],"a");
	 if(fd == NULL){
	  printf("Can't open target file.");
	  fclose(fs);
	  return 1;
	 }
	
	 while(1){
		ch=fgetc(fs);
	    if (feof(fs)) {
			break;
		}
	    fputc(ch,fd);
	 }
	puts("File copied in apend mode...");
	fclose(fs);
	fclose(fd);
	return 0;
}


