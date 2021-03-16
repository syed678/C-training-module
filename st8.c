/* Add the functionality of dynamic memory allocation to create a structure array  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {

   	char *name;
    int data;          // Data 
}*head;



static void insertData (void);
static void DisplayList( void);
static char* getstring(void);

static int NoOfNodes=0;

int main()
{
    int choice, data;
	head = NULL;
     char arrint[10]={0};	
	while(1)
	{
		LAB:
			printf("\nenter your choicefor Student details");
			printf("\n1 : Add Roll no\n2 : Display data  ");
			printf("\n10 : to exit\n");
			printf("\nenter your choice :  ");
		//	scanf("%d",&choice);
			
			gets(arrint);
			if(  CheckarrtoInt( arrint )){
				choice = atoi( arrint );
			}
			else{
				puts("enter valid no");
				memset(arrint,0,10);
				goto LAB;
			}
    
		
		
		switch (choice){
		case 1 : 
			printf("\nEnter data to insert in list: ");
		    insertData();
		break;
		case 2 : 
			printf("\nData in the list.... \n");
  		    DisplayList();
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

static void insertData (void)
{
	head = realloc(head ,(sizeof(struct node)) * ( NoOfNodes + 1 ) );
	char arrint[10]={0};
	if( NULL == head ){
		printf("memory allocation failed \n");
		return;
	}
	
	LAB1 :	
		printf("enter roll no   :  ");
	//	scanf("%d",&head[NoOfNodes].data);

		gets(arrint);
		if(  CheckarrtoInt( arrint )){
			head[NoOfNodes].data = atoi( arrint );
		}
		else{
			puts("enter valid no");
			memset(arrint,0,10);
			goto LAB1;
		}
	
//	getchar();
LAB2:	printf("enter Name  :\t");
		head[NoOfNodes].name = getstring();
	
		if ( ! CheckName( head[NoOfNodes].name ) ) {
				puts("enter Propper name");
			goto LAB2;
		}	
	
	
	printf("\nName : %s\t data : %d data Add in list",head[NoOfNodes].name,head[NoOfNodes].data);
	
	
	NoOfNodes +=1;
}

static void DisplayList(void )
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


