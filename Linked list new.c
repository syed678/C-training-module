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
#include"E:\Local\Desktop\update\array\Fun.c"

struct student { 
    int info; 
    char *Name;
    char Grade;
    struct student* link; 
};

void insertAtEnd( void );
void print( void );
void insertAtPosition(void );
void deletePosition( void );
void sort( void );
void swap(struct student *a, struct student *b);
void Edit( void );
void EditPyra (struct student *temp );
void FindElement(void );

struct student* start = NULL; 

int main() 
{ 
	
	int wrongChoice = 0;
    int choice; 
    while (1) { 
  		puts("\n...........___menu___...........");
		printf("\n 1 : Add at end"); 
        printf("\n 2 : Print list");   
        printf("\n 3 : Insert at any position"); 
        printf("\n 4 : Delete at any position"); 
        printf("\n 5 : To Sort an elements"); 
        printf("\n 6 : To Edit an element");
		printf("\n 7 : To Find an element");
        printf("\n 8 :  EXIT\n"); 
 		puts("=================================");
		printf("enter your choice :  ");
		choice = Enterdigit();
        switch (choice) { 
         
	        case 1: 
	            insertAtEnd(); 
				wrongChoice = 0;
	            break;
			case 2: 
	            print(); 
	            break;	 
	        case 3: 
	            insertAtPosition(); 
				wrongChoice = 0;
	            break;  
	        case 4: 
	            deletePosition();
				wrongChoice = 0; 
	            break;
	        case 5: 
	            sort(); 
				wrongChoice = 0;
	            break; 
	        case 6 :
	        	Edit();
				wrongChoice = 0;
	        	break;
		    case 7 :
	        	FindElement();
				wrongChoice = 0;
	        	break;
			case 8: 
				return; 
	            break; 
	        default:  wrongChoice++;
	            printf("\n....Invalid Entry......\n");         
        } 
		if( wrongChoice > 3 ){
				puts("Multiple time wrong entries ....");	
				wrongChoice = 0;
				return ;
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
	}while( p[index++] != '\n');

	p[index-1]=0;
	return p; 
	
}

char checkGrade(char *p)
{
	if ( (  p[1] == 0 ) && ( p[0] == 'A' || p[0] == 'B' || p[0] == 'C' || p[0] == 'D' || p[0] == 'E' || p[0] == 'F'||
							 p[0] == 'a' || p[0] == 'b' || p[0] == 'c' || p[0] == 'd' || p[0] == 'e' || p[0] == 'f' )  ){
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
	

	printf("\nEnter Roll number : "); 
	temp->info = EnterInt();
	while( temp->info < 1 ){
		puts("Invalid entry.... Enter again ");
		temp->info = EnterInt();
		
	}
	
 
    printf("\nEnter Name : "); 
	temp->Name =  getstring();
	while(  ! CheckName( temp->Name ) ){
		puts("enter Propper name");
		free(temp->Name); 
		temp->Name=NULL;
		temp->Name = getstring();
	}

	printf("\nEnterGrade : "); 
    gets(arrch);
	while( !checkGrade(arrch) ){
		puts("Invalid Entery");
		puts("enter Grade between A to F");
		gets(arrch);
	}
	if( arrch[0] > 96 )	{
		arrch[0] -= 32;	
	}
	temp->Grade = arrch[0];
	
	printf("\n %d\t", temp->info); 
	printf(" %s\t", temp->Name); 
	printf(" %c  .....data Added", temp->Grade); 
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  Add data in end like arrays*/
 void insertAtEnd( void ) 
{ 
    int data; 
    struct student *temp , *head; 
    temp = calloc(1,sizeof(struct student)); 
  	if(NULL == temp ){
  		puts("Memory allocation failed ");
  		return;
	  }
 	EnterInput(temp);	
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
 void print( void ) 
{ 
    struct student* temp; 
  	char n = 1; //for max 256 for sr.no if need more make it int
    if ( NULL == start ) {
    	printf("\nList is empty.....\n"); 
		return;	
	}
    // Else print the LL 
    else { 
         temp = start; 
         puts(" Student details :") ;
         printf("\nsr.n\tRoll no    Name\t\tGrade\t"); 
	     while (temp != NULL) { 
          	printf("\n%d\t %d",n++,temp->info); 
			printf("\t %s\t", temp->Name); 
			printf("\t %c", temp->Grade); 
            temp = temp->link; 
        } 
    } 
} 
   /* Insert nth position node in linked list if 2 enter 2nd node will be entered*/
 void insertAtPosition() 
{ 
    int data = 0,MaxPos = 1,i = 1,pos = 1; 
    struct student *temp = NULL, *head,* newnode = NULL; 
    if ( NULL == start ) {
    	printf("\nList is empty\n"); 
		MaxPos = 0;
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
   printf("\nEnter number between 1 to %d :", MaxPos); 
   	printf("\nEnter position and data to be insert :"); 
    pos = EnterInt();
   if( pos < 1 || pos > MaxPos ){
	   	puts("position out of range ");
	   	return;
	   }
    temp = start; 
    newnode = malloc(sizeof(struct student)); 
  	if(NULL == newnode ){
  		puts("memory allocation failed ");
  		return;
	  }
	EnterInput(newnode);
	if (pos == 1 )
	{
		newnode->link = start;
		start = newnode;
		return;
	}
	while ( i < pos - 1) { 
        temp = temp->link; 
        i++; 
    } 
   newnode->link = temp->link; //connection with new node
    temp->link = newnode; 	// connection list to new node 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* delerte nth position node in linked list if 2 enter 2nd node will, be delete*/
 void deletePosition() 
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
 
  	printf("\nEnter number between 1 to %d :", MaxPos); 
   	printf("\nEnter position , Data to be delete :"); 
    pos = EnterInt();
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
        //i starting from zero there for using pos-1
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
    printf("\nEnter position for Data Edit :"); 
    pos = EnterInt();
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
	int invalidCnt = 0,choice,pyrameter;
	char arrint[10]={0};
	char arrch[2]={0};
	do{
		puts(" 1 :  to edit All pyrameter enter \n 2 : to edit individual pyrameter enter  ");
		choice = Enterdigit();
		if( choice == 1 ){
			EnterInput(temp);
			invalidCnt = 0;
		}
		else if ( choice == 2 )
		{
			puts("1 : to edit Roll number ");
			puts("2 : to edit Name ");
			puts("3 : to edit grade ");
			pyrameter = EnterInt();
			switch( pyrameter ){
				case 1:printf("\nEnter Roll number : "); 
						    temp->info = EnterInt();
						   	while( temp->info < 1 ){
								puts("Invalid entry.... Enter again ");
								temp->info = EnterInt();
								
							}
						    invalidCnt = 0;
						 	break;
	    		case 2: 
							printf("\nEnter Name : "); 
							temp->Name =  getstring();
							while(  ! CheckName( temp->Name ) ){
								puts("enter Propper name");
								free(temp->Name); 
							    temp->Name=NULL;
								temp->Name = getstring();
							}
							invalidCnt = 0;
							break;
				case 3 :
							printf("\nEnterGrade : "); 
						    gets(arrch);
							while( !checkGrade(arrch) ){
								puts("Invalid Entery");
								puts("enter Grade between A to F");
								gets(arrch);
						}
						temp->Grade = arrch[0];
						invalidCnt = 0;
						break;
				default : puts("Invalid entry...."); 
						invalidCnt++;
			}	
		 } 
		 else
		 {
		 	puts("invalid entery ..");
		 	invalidCnt++;
		 }	
	}while(invalidCnt > 0 && invalidCnt <= 3);	
	if(invalidCnt >=3){
		puts(" Multiple time wrong option entered....");	
	}
	else{
		puts(" Data modified....");	
	}		
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sort() 
{ 
    int swapped, i; 
    struct student *ptr1; 
    struct student *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL){
    	puts("list Empty...");
		return; 	
	}
      
    do{ 
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
  
/* function to swap data of two nodes */
void swap(struct student *a, struct student *b) 
{ 
  	//due to Link pointer swap data not direct node
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


void FindElement(void )
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
   	 printf("\Enter number between 1 to %d :", MaxPos+1);//bcoz starting with zero there for + 1 here
    printf("\nEnter position to be find :"); 
    pos = EnterInt();
    temp = start;
	while(i != pos){
    	i++;
		temp= temp->link;	
	}
    
	if( i == pos ){
    	puts(" Found & Student detail... :") ;
         printf("Roll no    Name\t\tGrade\t"); 
          	printf("\n %d", temp->info); 
			printf("\t %s\t", temp->Name); 
			printf("\t %c", temp->Grade); 
   		 
	}
}
