/* Demonstrating the concept of call by value and call by reference (pass a structure to the
function, perform the operation on it (structure member) and print values in the main function). */
/* this is call by reference */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    	
	while(1)
	{
		printf("\nenter your choicefor Student details");
		printf("\n1 : Add Roll no\n2 : Display data  ");
		printf("\n10 : to exit\n");
		printf("\nenter your choice :  ");
		scanf("%d",&choice);
		switch (choice){
		case 1 : 
			printf("\nEnter data to insert in list: ");
		    head = insertData(head);
		break;
		case 2 : 
			printf("\nData in the list.... \n");
  		    DisplayList( head );
		break;
		case 10 : 
			return;
		break;
		default : printf("wrong choice enterd\n");
		}
	}		
    return 0;
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
	char arrint[10]={0};
	head = realloc(head ,(sizeof(struct node)) * ( NoOfNodes + 1 ) );
	if( NULL == head ){
		printf("memory allocation failed \n");
		return;
	}
	
	
//	printf("enter roll no   :  ");
//	scanf("%d",&head[NoOfNodes].data);
	
	LAB1 :	
		printf("enter roll no   :  ");
			getchar();
		gets(arrint);
		if(  CheckarrtoInt( arrint )){
			head[NoOfNodes].data = atoi( arrint );
		}
		else{
			puts("enter valid no");
			memset(arrint,0,10);
			goto LAB1;
		}
	
//
LAB2:
	printf("enter Name  :\t");
	head[NoOfNodes].name = getstring();
	
	if ( ! CheckName( head[NoOfNodes].name ) ) {
				puts("enter valid name");
				goto LAB2;
			}
	
	
	printf("\nName : %s\t data : %d data Add in list",head[NoOfNodes].name,head[NoOfNodes].data);
		
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




