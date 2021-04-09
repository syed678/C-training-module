/*Copy contents of the file to another file.
2file_mrgr.exe f1.txt f2.txt f3.txt*/

#include<stdio.h>
int main(int argc,char *argv[])
{
	 FILE *fs1,*fd,*fs2;
	 int ch;
	 if(argc!=4)
	 {
	  printf("Invalide numbers of arguments.");
	  return 1;
	 }
	 fs1=fopen(argv[1],"r");
	 if(fs1==NULL)
	 {
	  printf("source file not found.");
	  return 1;
	 }
	 fs2=fopen(argv[2],"r");
	 if(fs2==NULL)
	 {
	  printf("source file not found.");
	  return 1;
	 }
	 
	 fd=fopen(argv[3],"w");
	 if(fd==NULL)
	 {
	  printf("Can't open target file.");
	  fclose(fd);
	  return 1;
	 }
	char flag1 =1,flag2=1;;
	 while(flag1 || flag2 ){
			if(flag1)	{
				ch=fgetc(fs1);
			    if (ch == EOF) {
			    	flag1 =0;	
				}
			    else{
			    fputc(ch,fd);		
				}
			}
			if(flag2){
				ch=fgetc(fs2);
			    if (ch == EOF) {
			    	flag2 = 0;	
				}
			    else{
			    	fputc(ch,fd);	
				}			
			}	
	   }
	
	 fclose(fs1);
	 fclose(fs2);
	 fclose(fd);
	 puts("Data copied....");
	 return 0;
}


