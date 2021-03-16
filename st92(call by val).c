/* Demonstrating the concept of call by value and call by reference (pass a structure to the
function, perform the operation on it (structure member) and print values in the main function). */
/* this is call by value */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {

   	char *name;
    int data;          // Data 
};



static struct node *  insertData (struct node *var);
static char* getstring(void);
static int NoOfNodes = 0;
int main()
{
    int choice, data;
	struct node variable ;
    	

	printf("\nenter Student details");
	printf("\n Add Data no ");
	printf("\nEnter data to insert in list: ");
	memcpy(&variable, insertData( &variable ), sizeof (variable) );
	printf("\nData is.... \n");
	printf("\nName : %s\t Roll no : %d",variable.name,variable.data);	
	
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

static struct node * insertData (struct node *var)
{
	
	char arrint[10]={0};
	var = calloc(1 , 8 /*sizeof (struct node */);
	
	if( NULL == var ){
		printf("memory allocation failed \n");
		return;
	}
	
	
//	printf("enter roll no   :  ");
//	scanf("%d",&var->data);
	
	LAB1 :	
		printf("enter roll no   :  ");
		gets(arrint);
		if(  CheckarrtoInt( arrint )){
			var->data = atoi( arrint );
		}
		else{
			puts("enter valid no");
			memset(arrint,0,10);
			goto LAB1;
		}
	
	
	
	
//	getchar();
	LAB2:
		printf("enter Name  :\t");
		var->name = getstring();
	
		if ( ! CheckName( var->name ) ) {
				puts("enter valid name");
				goto LAB2;
			}
	
	printf("\nName : %s\t data : %d data saved",var->name,var->data);
		
	
	return var;
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





