/*
Take a structure and define some parameters relating to it so we get bunch of elements (eg. StructureStudent, Parameters - Roll number, Name, Grade).
? Display all elements of list.
? Add new elements to list (at nth position in list)
? Find an element from list.
? Delete an element from list.
? Modify any parameter of any element from list.
? Sort all elements of list depending on any one parameter.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student { 
    int info; 
    char *Name;
    char Grade;
    struct student* link; 
};

static void insertAtEnd( void );
static void print( void );
static void insertAtPosition(void );
static void deletePosition( void );
 void sort( void );
 void swap(struct student *a, struct student *b);
//static void swap(struct student *a, struct student *b);
void Edit( void );
void EditPyra (struct student *temp );
 
struct student* start = NULL; 



int main() 
{ 
	char Arrint[2];
    int choice; 
    while (1) { 
  		puts("\n.......___menu___..............");
		printf("\n 1 : For Add at end"); 
        printf("\n 2 :  To print list");   
        printf("\n 3 :  For insertion at any position"); 
        printf("\n 4 :  For deletion of element at any position"); 
        printf("\n 5 To sort element"); 
        printf("\n 6 To Edit element"); 
        printf("\n 9 : To Exit\n"); 
	    printf("Enter Choice :   "); 
	//	scanf("%d", &choice); 
LABEL : 
		printf("enter your choice :  ");
		scanf("%s",Arrint);
		if( checkInt0to10(Arrint) ){
	    choice =   Arrint[0] -48  ;
		}
		else{
			puts("Invalid Entery");
			goto LABEL;
			
		}
        switch (choice) { 
         
	        case 1: 
	            insertAtEnd(); 
	            break;
			case 2: 
	            print(); 
	            break;	 
	        case 3: 
	            insertAtPosition(); 
	            break;  
	        case 4: 
	            deletePosition(); 
	            break;
	        case 5: 
	            sort(); 
	            break; 
	        case 6 :
	        	Edit();
	        	break;
		    case 9: 
				return; 
	            break; 
	        default: 
	            printf("\n....Invalid Entry......\n"); 
	            
        } 
 //   getchar();
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
	}while( p[index++] != '\n');

	p[index-1]=0;
	
	return p; 
	
}

int checkInt0to10(char*p)
{
	if(  ( p[0] >= '0' && p[0] <= 10) || p[1] == 0 )
			return 1;
			else
			 return 0;
			
}


int CheckarrtoInt(char*p)
{
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
	int i;
	for(i= 0 ; p[i]; i++ ){
	
	//	if( !  () ( isalpha(p[i]) ) || p[i] == ' ' || p[i] == 0)
		if( !  ( ( isalpha(p[i]) ) || p[i] == ' ' || p[i] == 0) ) 
			return 0;
		}
		return 1;
	
	
}

int checkGrade(char *p)
{
	if ( (  p[1] == 0 ) && ( p[0] == 'A' || p[0] == 'A' || p[0] == 'B' || p[0] == 'C' || p[0] == 'D' || p[0] == 'E' || p[0] == 'F'||
		p[0] == 'a' ||p[0] == 'b' ||p[0] == 'c' ||p[0] == 'd' ||p[0] == 'e' ||p[0] == 'f' )  ){
		return 1;
		}
		else{
			return 0;
		}
	
}

void EnterInput(struct student *temp)
{
	char arrint[10];
	char arrch[2];
	
Label1:
	printf("\nEnter Roll number : "); 
    scanf("%s",arrint);
	if(  CheckarrtoInt( arrint )){
		temp->info = atoi( arrint );
	}
	else{
		puts("enter correct roll no");
		memset(arrint,0,10);
		goto Label1;
	}
	//scanf("%d", &); 
    
 LABEL2:
    printf("\nEnter Name : "); 
	getchar();
	temp->Name =  getstring();
	if ( ! CheckName( temp->Name ) ) {
			puts("enter Propper name");
		goto LABEL2;
	}
	
LABEL3:	
	printf("\nEnterGrade : "); 
    gets(arrch);
    if( checkGrade(arrch) ){
    temp->Grade = arrch[0];
	}
	else{
		puts("Invalid Entery");
		puts("enter Grade between A to F");
		goto LABEL3;
		
	}
	
//scanf("%c", &temp->Grade); 
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  Add data in end like arrays*/
static void insertAtEnd( void ) 
{ 
    int data; 
    struct student *temp , *head; 
    temp = calloc(1,sizeof(struct student)); 
  	if(NULL == temp ){
  		puts("memory allocation failed ");
  		return;
	  }
    // Enter the number 
 	EnterInput(temp);
 
 
 /*  printf("\nEnter Roll number : "); 
    scanf("%d", &temp->info); 
    
    printf("\nEnter Name : "); 
	getchar();
	temp->Name =  getstring();
   
	printf("\nEnterGrade : "); 
    scanf("%c", &temp->Grade); 
    
  */
    // Changes links 
   if ( NULL == start ) {
    	start = temp;
		return;	
	}
    head = start; 
    while ( NULL != head->link) { 
        head = head->link; 
    } 
    head->link = temp; 
} 
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  to print student data */
static void print( void ) 
{ 
    struct student* temp; 
  
    // List is empty 
    if ( NULL == start ) {
    	printf("\nList is empty\n"); 
		return;	
	}
    // Else print the LL 
    else { 
         temp = start; 
         puts(" Student details :") ;
         printf("\nRoll no \t Name\t\tGrade\t"); 
	     while (temp != NULL) { 
          	printf("\n %d", temp->info); 
			printf("\t %s\t", temp->Name); 
			printf("\t %c", temp->Grade); 
            temp = temp->link; 
        } 
    } 
} 


/*  if enter 1st data will add after 1st node
if 0 enter data will addd bin 1st node

*/ 
static void insertAtPosition() 
{ 
    
	int data = 0,MaxPos = 0,i = 0,pos; 
    struct student *temp = NULL, *head,* newnode = NULL; 
    
   
   	if ( NULL == start ) {
    	printf("\nList is empty\n"); 
		return;	
	}
    // Else print the LL 
    else { 
         temp = start; 
        	
	     while (temp != NULL) { 
          	MaxPos += 1;	
            temp = temp->link; 
    	}//while
	}//else	
   	temp = 0;
   char posarr[10]={0};
 L1:
  	 printf("\nEnter number between 1 to %d :", MaxPos); 
   	printf("\nEnter position and data to be insert :"); 
    //scanf("%d", &pos); 
    scanf("%s",posarr);
	if(  CheckarrtoInt( posarr )){
		pos = atoi( posarr );
	}
	else{
		puts("enter correct position ");
		goto L1;
	}
    if(pos < 0 || pos > MaxPos){
	   	puts("position out of range ");
	   	return;
	   }
    
      newnode = malloc(sizeof(struct student)); 
  	if(NULL == newnode ){
  		puts("memory allocation failed ");
  		return;
	  }
  
    printf("\nEnter Roll number : "); 
    scanf("%d", &newnode->info); 
    printf("\nEnter Name : "); 
    getchar();
	newnode->Name =  getstring();
  // gets( newnode->Name );
    printf("\nEnterGrade : "); 
    scanf("%c", &newnode->Grade); 
    
  
    // Changes links 
 
    temp = start; 
    while (i < pos - 1) { 
        temp = temp->link; 
        i++; 
    } 
    newnode->link = temp->link; //connection with new node
    temp->link = newnode; 	// connection list to new node 
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* delerte nth position node in linked list if 2 enter 2nd node will, be delete*/
static void deletePosition() 
{ 
    struct student *temp = NULL , *prev = NULL; 
   	int MaxPos = 0,i = 0,pos; 
  
  
    // If LL is empty 
    if (start == NULL) {
    	printf("\nList is empty\n");
    	return;
    }
	else { 
         temp = start; 	//count max number of node
	     while (temp != NULL) { 
          	MaxPos += 1;	
            temp = temp ->link; 
    	}//while
	}//else	
   	temp = 0;    
    // Otherwise 
    
    char posarr[10]={0};
 L2:
  	 printf("\nEnter number between 1 to %d :", MaxPos); 
   	printf("\nEnter position and data to be insert :"); 
    scanf("%s",posarr);
	if(  CheckarrtoInt( posarr )){
		pos = atoi( posarr );
	}
	else{
		puts("enter correct position ");
		goto L2;
	}
    if(pos < 1 || pos > MaxPos){
	   	puts("position out of range ");
	   	return;
	   }
    
    
  
       
	 if(1 == pos ){// if first node
     	temp = start;
     	start = start->link;
	 	free(temp);
	 	temp = NULL;
	 	return;
	 }
	   
     else{
     	  temp = start; 
  
        // Traverse till position 
        while (i < pos - 1) { 
            prev = temp;
			temp = temp->link;
			i++; 
        } 
  	 prev ->link = temp->link; 
    free(temp); 
    temp = NULL;
    }
} 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Edit( void ) 
{ 
    int choice,pyrameter=0,invalidCnt=1;
	int MaxPos = 0,i = 1,pos = 1; 
    struct student *temp = NULL; 
    
   	if ( NULL == start ) {
    	printf("\nList is empty\n"); 
		return;	
	}
	else{
		temp = start;
		while(temp->link){
    	MaxPos++;
		temp= temp->link;	
		}	
	}
   	 printf("\Enter number between 1 to %d :", MaxPos+1);//bcoz starting with zero add 1 here
    printf("\nEnter position to be Edit :"); 
    scanf("%d", &pos); 
    temp = start;
	while(i != pos){
    	i++;
		temp= temp->link;	
	}
    
	if( i == pos ){
    	EditPyra(temp);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EditPyra (struct student *temp )
{
	int invalidCnt = 1,choice,pyrameter;
	char arrint[10]={0};
	char arrch[2]={0};
LABEL:
	puts(" 1 :  to edit All pyrameter enter ");
	puts(" 2 : to edit 1 pyrameter enter ");
	scanf("%d",&choice);
	
	if( choice == 1 ){
	EnterInput(temp);
/*	printf("\nEnter Roll number : "); 
    scanf("%d", &temp->info); 
    printf("\nEnter Name : "); 
    getchar();
	temp->Name =  getstring();
    printf("\nEnter Grade : "); 
    scanf("%c", &temp->Grade); 	
*/	}
	else if ( choice == 2 )
	{
		puts("1 : to edit Roll number ");
		puts("2 : to edit Name ");
		puts("3 : to edit grade ");
		scanf("%d",&pyrameter);
		switch( pyrameter ){
			case 1 : LAB1:
							printf("\nEnter Roll number : "); 
						    scanf("%s",arrint);
							if(  CheckarrtoInt( arrint )){
								temp->info = atoi( arrint );
							}
							else{
								puts("enter correct roll no");
								memset(arrint,0,10);
								goto LAB1;
							} 
					/*printf("\nEnter Roll number : "); 
    				 scanf("%d", &temp->info); 
    				*/ break;
    		case 2 : LAB2:
						    printf("\nEnter Name : "); 
							getchar();
							temp->Name =  getstring();
							if ( ! CheckName( temp->Name ) ) {
									puts("enter Propper name");
								goto LAB2;
							}
			
					/* printf("\nEnter Name : "); 
				     getchar();
				  	temp->Name = getstring();	
				  */	break;
			case 3 :LAB3:	
							printf("\nEnterGrade : "); 
						    gets(arrch);
						    if( checkGrade(arrch) ){
						    temp->Grade = arrch[0];
							}
							else{
								puts("Invalid Entery");
								puts("enter Grade between A to F");
								goto LAB3;
							}
				
					/*printf("\nEnter Grade : "); 
				    scanf("%c", &temp->Grade); 	
					*/break;
			default : puts("Invalid entry...."); 
					invalidCnt++;
		}
		
	 } 
	 else
	 {
	 	puts("invalid entery ..");
	 	invalidCnt++;
	 }
	if ( invalidCnt > 1 ){	
			if( invalidCnt > 3){
				puts(" Multiple time wrong option entered....");
				return;
			}
		goto LABEL;
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sort() 
{ 
    int swapped, i; 
    struct student *ptr1; 
    struct student *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->link != lptr) 
        { 
            if (ptr1->info > ptr1->link->info) 
            {  
                swap(ptr1, ptr1->link); 
                swapped = 1; 
            } 
            ptr1 = ptr1->link; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  
/* function to swap data of two nodes a and b*/
void swap(struct student *a, struct student *b) 
{ 
   char *p;
   char ch;
   int temp ;
   	temp = a->info; 
    a->info = b->info; 
    b->info = temp; 
    
    ch = a->Grade; 
    a->Grade = b->Grade; 
    b->Grade = ch; 
    
    p = a->Name; 
    a->Name = b->Name; 
    b->Name = p; 
    
} 
