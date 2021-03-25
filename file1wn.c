/*A file name is command line argument. Display the contents of the file where each word will
be displayed on a new line. Display proper message if file does not exist.
 file1wn.exe f1.txt  */
 //if condition brac modified & array[20]={0} removed


#include<stdio.h>
int main(int argc,char *argv[])
{
	 FILE *fp;
	 int cnt=0;
	 char ch;
	 char *pcBuf=NULL;
	 if( argc!= 2)
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

	while(1){
	  	ch = fgetc(fp);
		if (feof(fp)) {
			break;
		}
	
		if(ch == ' ' || ch == '\n' ){
		 	puts("");
		 }
		 else{
		 		putchar(ch);
		 }
	}
	fclose(fp);
	return 0;
}



/*	while( fscanf(fp, "%s",array) != EOF ){
		puts(array);	
    	memset(array,0,20);
    	}
*/


/* //pcBuf = realloc(pcBuf,cnt+1);//allocating memory to store bytes
	  pcBuf[cnt] = ch;
	  putchar(ch);
	  if(pcBuf[cnt] == ' ' || pcBuf[cnt] == '\n' ){
		  //	pcBuf = realloc(pcBuf,cnt+1);
		//	pcBuf[cnt] = 0;
		//	puts( pcBuf );
		//	free(pcBuf);
		//	pcBuf = NULL;
			puts("\n");
			cnt=0;
	  	}
	  	cnt++;
	  	if (feof(fp)) break;*/
