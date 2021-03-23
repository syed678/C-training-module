/* Demonstrating the concept of call by value and call by reference (pass a structure to the
function*/
/* this is call by value */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"E:\Local\Desktop\update\array\Fun.c"

struct node {

   	char *name;
    int data;          // Data 
};



static struct node *  insertData (struct node *var);
static char* getstring(void);
static int NoOfNodes = 0;
void print(struct node variable );

int main()
{
    int choice, data;
	struct node variable ;
 	printf("\t..... Student details.......\n");
	memcpy(&variable, insertData( &variable ), sizeof (variable) );
	print(variable); // using call by value
		
	
    return 0;
}


void print(struct node variable )
{
	printf("\nData is.... \n");
	printf("\nName : %s\t Roll no : %d",variable.name,variable.data);
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
	var = calloc(1 , sizeof (*var) );
	int erroecnt = 1;
	if( NULL == var ){
		printf("memory allocation failed \n");
		return;
	}
	puts("enter Roll no");
	var->data = EnterInt();

	printf("enter Name  :\t");
	var->name = getstring();
	while(  ! CheckName( var->name )  )
	{
		puts("enter Propper name");
		free(var->name);  var->name=NULL;
		var->name = getstring();
	}

/*	LAB2:
		printf("enter Name  :\t");
		var->name = getstring();
		if ( ! CheckName( var->name ) ) {
				puts("enter valid name");
				goto LAB2;
			}
*/	printf("\nName : %s\t data : %d data saved",var->name,var->data);
		
	
	return var;
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





