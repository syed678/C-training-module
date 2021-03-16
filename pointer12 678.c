/*  2d array */

#include<stdio.h>
#include<string.h>

int checkinterror(char *);
static int CheckarrtoInt(char*);

int main()
{
   /* 2D array declaration*/
   int disp[2][3];	//means 2 no. of 1 d array each has 3 member of int   2*3 means 6 elements size will be 4*2*3 =24
   /*Counter variables for the loop*/
   int i, j;
   char arrint[10] = {0};	
  fflush(stdin);
    puts("2d array example ...");
   for(i=0; i<2 ; i++) {
	      for( j=0 ; j<3 ;j++) {
	         printf("Enter value for disp[%d][%d]:", i, j);
	     //   scanf("%s",arrint);
			disp[i][j] = checkinterror(arrint);
			memset(arrint,0,10);
			
			// scanf("%d", &disp[i][j]);
		 }
	   }
   //Displaying array elements
   printf("Two Dimensional array elements:\n");
   for(i=0; i<2; i++,printf("\n")) {
      for(j=0;j<3;j++) {
         printf("%d\t", disp[i][j]);
      }
   }
   
	
return 0;
}



static int CheckarrtoInt(char*p)
{
	//checking int or other data?
	//if int return 1
	int i;
	for(i=0;i<10;i++){
		if(  ( isdigit(p[i]) || p[i] == 0) )
			continue;
			else
			 return 0;
			
	}	
	return 1;
}

int checkinterror(char *arrint)
{

	Label1:
			printf("\nEnter number : "); 
		    scanf("%s",arrint);
			if(  CheckarrtoInt( arrint ) ){
				
				return(atoi( arrint ) ); 
			}
			else{
				puts("enter valid no");
				memset(arrint,0,10);
				goto Label1;
			}
return 0;
}
