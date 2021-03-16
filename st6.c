/*  array of structure example */

#include <stdio.h>
#include<string.h>
int i;
struct student {
	
char name[30];
int rollno;

} stud[3];

main()
{
	 char arrint[10]={0};
	puts("enter 3 students details :......\n");
	for(i=0; i<3; i++){
	
	
		//scanf ("%d",&stud[i].rollno);
		
		LAB: 
			printf ("\nEnter your RollNo : ");
			gets(arrint);
			if(  CheckarrtoInt( arrint )){
				stud[i].rollno = atoi( arrint );
			}
			else{
				puts("enter valid no");
				memset(arrint,0,10);
				goto LAB;
			}
	
	
	
			LABEL:
				
			   	printf("Enter name: ");
			   gets( stud[i].name);
			
				if ( ! CheckName(  stud[i].name ) ) {
						puts("enter Propper name");
					goto LABEL;
				}
			
	
	}
	printf ("\nList of all records");
	for (i=0; i<3; i++)
	{
	printf ("\nRollNo : %d\t Name : %s", stud[i].rollno, stud[i].name);
	}
	return 0;
}


int CheckarrtoInt(char*p)
{	//check int value valid or not
	int i;
	for(i=0;i<10;i++){
		if(  ( isdigit(p[i]) || p[i] == 0) )
			continue;
			else
			 return 0;
			
	}	
	return 1;
}

int CheckName (char *p)
{
	//check name valid or not
	int i;
	for(i= 0 ; p[i]; i++ ){
	
	//	if( !  () ( isalpha(p[i]) ) || p[i] == ' ' || p[i] == 0)
		if( !  ( ( isalpha(p[i]) ) || p[i] == ' ' || p[i] == 0) ) 
			return 0;
		}
		return 1;
	
	
}

