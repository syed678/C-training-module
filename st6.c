/*  array of structure example */

#include <stdio.h>
#include<string.h>
#include"E:\Local\Desktop\update\array\Fun.c"

#define  SIZE 3

int i;
struct student {
	
	char name[30];
	int rollno;

} stud[3];

main()
{
	 char arrint[10]={0};
	 int errorcnt = 0;
	puts("enter 3 students details :......\n");
	for(i=0; i<SIZE; i++){
		puts("Roll number");
		stud[i].rollno = EnterInt();
		printf("Enter name: ");
	
		do{	
			if( errorcnt > 2 ){
				puts("Multiple time wrong entries......");	
				return ;
			}	
			if(	errorcnt  )	puts("enter Propper name");
			gets( stud[i].name);
			errorcnt++;
		}while(  ! CheckName(  stud[i].name ) );
	
		errorcnt =0;
	}
	printf ("\nList of all records");
	for (i=0; i<SIZE; i++)
	{
	printf ("\nRollNo : %d\t Name : %s", stud[i].rollno, stud[i].name);
	}
	return 0;
}



int CheckName (char *p)
{
	//check name valid or not
	int i;
	for(i= 0 ; p[i]; i++ ){
	
	if( !  ( ( isalpha(p[i]) ) || p[i] == ' ' || p[i] == 0 )  ||  ( p[i] == ' ' && p[i+1] == ' ')) 
			return 0;
		}
		return 1;
	
	
}

