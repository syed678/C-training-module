/* Add the functionality of dynamic memory allocation to create a structure array  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"E:\Local\Desktop\update\array\Fun.c"
struct node {

   	char *name;
    int data;          // Data 
}*head;



 void insertData (void);
 void DisplayList( void);
 char* getstring(void);

static int NoOfNodes=0;

int main()
{
    int choice, data;
	head = NULL;
	int errorcnt = 0;
    char arrint[10]={0};	
	while(1)
	{
		puts("\n\t________MENU______");
		printf("\nenter your choicefor Student details");
		printf("\n1 : Add Roll no\n2 : Display data  ");
		printf("\n3 : to exit\n");
		printf("\nenter your choice :  ");
		choice = Enterdigit();
		switch (choice){
		case 1 : 
			printf("\nEnter data to insert in list: ");
		    errorcnt=0;
			insertData();
		break;
		case 2 : 
			printf("\nData in the list.... \n");
  		   errorcnt =0;
			  DisplayList();
		break;
		case 3 : 
			return;
		break;
		default : printf("wrong choice enterd\n");
					errorcnt++;
		
		}
		if(errorcnt > 2)
			 {
				printf("Multiple time wrong choice enterd\n");
				return 0;
		}
	}	
}

 char* getstring(void)
{
	char *p = NULL;
	char index = 0;
	char ch;
	do{
		ch =getchar();
		p = realloc(p,index+1);
		p[index] = ch;
	}while( p[index++]!='\n');

	p[index-1]=0;
	return p; 
	
}

 void insertData (void)
{
	head = realloc(head ,(sizeof(struct node)) * ( NoOfNodes + 1 ) );

	if( NULL == head ){
		printf("memory allocation failed \n");
		return;
	}
	
		
	printf("enter roll no   :  ");
	head[NoOfNodes].data = EnterInt();

	printf("Enter name: ");
	head[NoOfNodes].name = getstring();	
	while(  ! CheckName( head[NoOfNodes].name )  )
	{
		puts("enter Propper name");
		free(head[NoOfNodes].name);  head[NoOfNodes].name=NULL;
		head[NoOfNodes].name = getstring();
	}	
/*		
LAB2:	printf("enter Name  :\t");
		head[NoOfNodes].name = getstring();
	
		if ( ! CheckName( head[NoOfNodes].name ) ) {
				puts("enter Propper name");
			goto LAB2;
		}	
*/	
	
	printf("\nName : %s\t data : %d data Add in list",head[NoOfNodes].name,head[NoOfNodes].data);
	
	
	NoOfNodes +=1;
}

 void DisplayList(void )
{
	int index = 0;
	if ( 0 == NoOfNodes ){
		printf("list Emoty \n");
		return;	
	}
	for ( index = 0; index < NoOfNodes ;index++ ){
		printf("\nName : %s\t Roll no : %d",head[index].name,head[index].data);	
	}
		
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


