/* Demonstrating the concept of call by value and call by reference (pass a structure to the
function, perform the operation on it (structure member) and print values in the main function). */
/* this is call by reference */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"E:\Local\Desktop\update\array\Fun.c"
struct node {

   	char *name;
    int data;          // Data 
};

static struct node * insertData (struct node *head);
static void DisplayList( struct node *head);
static char* getstring(void);
static int NoOfNodes = 0;
int main()
{
    int choice, data;
	struct node *head = NULL;
    	int errorcnt = 0;	
	while(1)
	{	puts("\n\t........MENU........");
		printf(" 1: Add data\t 2 : Display data  ");
		printf("\n\t3 : to exit\n");
		printf("\nenter your choicefor Student details");
		printf("\nenter your choice :  ");
		choice = Enterdigit();
		switch (choice){
		case 1 : 
			errorcnt=0;
		    head = insertData(head);
		break;
		case 2 : 
			errorcnt=0;
  		    DisplayList( head );
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

static char* getstring(void)
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

static struct node * insertData (struct node *head)
{
	
	head = realloc(head ,(sizeof(struct node)) * ( NoOfNodes + 1 ) );
	if( NULL == head ){
		printf("memory allocation failed \n");
		return;
	}
	printf("\nEnter Roll number \n");
	head[NoOfNodes].data = EnterInt();
	
	printf("enter Name  :\t");
	head[NoOfNodes].name = getstring();
	while(  ! CheckName( head[NoOfNodes].name )  )
	{
		puts("enter Propper name");
		free(head[NoOfNodes].name);  head[NoOfNodes].name=NULL;
		head[NoOfNodes].name = getstring();
	}

/*	
LAB2:
	printf("enter Name  :\t");
	head[NoOfNodes].name = getstring();
	if ( ! CheckName( head[NoOfNodes].name ) ) {
				puts("enter valid name");
				goto LAB2;
			}
*/	printf("\nName : %s\t data : %d data Add in list",head[NoOfNodes].name,head[NoOfNodes].data);
	NoOfNodes +=1;
	return head;
}

static void DisplayList( struct node *head )
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
	
			if( ! ( ( isalpha(p[i]) ) || p[i] == ' ' || p[i] == 0 )  ||  ( p[i] == ' ' && p[i+1] == ' '))
			return 0;
		}
		return 1;
	
	
}




