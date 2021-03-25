/* Demonstrating the concept of call by value and call by reference (pass a structure to the
function, perform the operation on it (structure member) and print values in the main function). */
/* this is call by reference */

#include<stdio.h>
#include"E:\Local\Desktop\update\array\Fun.c"
struct node {
    int data;          // Data 
};

struct node * insertData (struct node *head);
void DisplayList( struct node *head);
char* getstring(void);
void CheckCallbyval(struct node var);
void CheckCallbyRef(struct node *);

static int NoOfNodes = 0;
int main()
{
    int choice, data;
	struct node *head = NULL;
    int errorcnt = 0;
	int Index;	
	while(1)
	{	puts("\n\t........MENU........");
		printf("\n1: Add data\t\t 2 : Display data  ");
		printf("\n3: For call by value ");
		printf("\t4: For call by reference ");
		printf("\n\t   5:  EXIT...\n");
		printf("\n Enter your choice :  ");
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
		case 3 :printf("enter sr.no to be edit\n");
				Index = EnterInt();
				while( Index < 1  || Index > NoOfNodes){
					puts("Invalid entry.... Enter again ");
					Index = EnterInt();
					
				}
				CheckCallbyval(head[Index-1]);
				errorcnt = 0;	
				break;
		
		case 4 :printf("enter sr.no to be edit\n");
				Index = EnterInt();
				while( Index < 1  || Index > NoOfNodes){
					puts("Invalid entry.... Enter again ");
					Index = EnterInt();
					
				}
				CheckCallbyRef(& head[Index-1] );
				
				errorcnt = 0;	
				break;
		case 5 : 
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

 struct node * insertData (struct node *head)
{
	
	head = realloc(head ,(sizeof(struct node)) * ( NoOfNodes + 1 ) );
	if( NULL == head ){
		printf("memory allocation failed \n");
		return;
	}
	printf("\nEnter Roll number \n");
	head[NoOfNodes].data = EnterInt();
	while( head[NoOfNodes].data < 1 ){
			puts("Invalid entry.... Enter again ");
			head[NoOfNodes].data = EnterInt();
		}
	

	printf("\n data : %d data Add in list",head[NoOfNodes].data);
	NoOfNodes +=1;
	return head;
}

 void DisplayList( struct node *head )
{
	int index = 0;
	if ( 0 == NoOfNodes ){
		printf("list Emoty \n");
		return;	
	}
	for ( index = 0; index < NoOfNodes ;index++ ){
		printf("\n Roll no : %d",head[index].data);	
	}
		
}

void CheckCallbyval(struct node var)
{
	puts("here we are updating values but data should not update due to call by value");
		printf("\nEnter Roll number \n");
	var.data = EnterInt();
	while( var.data < 1 ){
			puts("Invalid entry.... Enter again ");
			var.data = EnterInt();
		}	
}

void CheckCallbyRef(struct node *p)
{
	puts("here we are updating values and data should update due to call by Reference");
		printf("\nEnter Roll number \n");
	p->data = EnterInt();
	while( p->data < 1 ){
			puts("Invalid entry.... Enter again ");
			p->data = EnterInt();
		}
}


