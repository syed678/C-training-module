/*
Perform the following operations on integer array of 10 elements.
É‹ Accept the values from user.
É‹ Sort an array in ascending order.
É‹ Sort an array in descending order.
É‹ Display sum of all odd values stored in an array.
É‹ Display number of even values stored in an array.
É‹ Set bits of odd position elements and clear bits of even position elements
*/
#include<stdio.h>
#include<string.h>
#define SIZE 10

static int array[SIZE];

static void SortArrayInAscendingOrder(void);
static void SortArrayInDescendingOrder(void);
static void  PrintArray(void);
static void DispSumOfOddVal(void);
static void DispSomeOfEvenVal(void);
static void SetBitOfOddPos(void);	
static void SetOddClrEvenbit(void);


main()
{
	char   temp = 0;
	char Arrint[2];
	char arrint[10]={0};
	int choice = 0;
	printf("enter 10 int\n");
	
	for(temp=0 ; temp<SIZE ; temp++){
		Label1:
				printf("\nEnter number : "); 
			    scanf("%s",arrint);
				if(  CheckarrtoInt( arrint )){
					array[temp] = atoi( arrint );
				}
				else{
					puts("enter valid no");
					memset(arrint,0,10);
					goto Label1;
				}
				//scanf("%d",&array[temp]);
	}
	PrintArray();
	
	while(1)
	{
		printf("enter your choice\n");
		printf("\n1 : Sort an array in ascending order\n2 : Sort an array in descending order  ");
		printf("\n3 : Display sum of all odd values stored in an array\n4 : Display number of even values stored in an array");
		printf("\n5 . Set bits of odd position elements clear bits of even position elements\n");
		printf("\n10 to exit\n");
LABEL :	printf("enter your choice :  ");
		scanf("%s",Arrint);
		if( checkInt(Arrint) ){
	    choice =   Arrint[0] -48  ;
		}
		else{
			puts("Invalid Entery");
			goto LABEL;
			
		}
	//	scanf("%d",&choice);
		switch (choice){
		case 1 : 
			SortArrayInAscendingOrder();
			PrintArray();
		break;
		case 2 : 
			SortArrayInDescendingOrder();
		break;
		case 3 : 
			DispSumOfOddVal();
		break;
		case 4 : 
			DispSomeOfEvenVal();
		break;	
		case 5 : 
			SetOddClrEvenbit();
		break;
	
		case 10 : 
			return;
		break;
		default : printf("wrong choice enterd\n");
		}
	
	}			

}


int checkInt(char*p)
{	//here checking char for 0to 10 or not
	if(  ( p[0] >= '0' && p[0] <= 10) || p[1] == 0 )
			return 1;
			else
			 return 0;
			
}


int CheckarrtoInt(char*p)
{
	//checking int or other data?
	//if int return 1
	int i;
	for(i=0;i<10;i++){
		if(  ( isdigit(p[i]) || p[i] == 0) )
			continue;
			else
			 return 0;
			
	}	
	return 1;
}


static void  PrintArray(void)
{
	char temp;
	printf("now array : ");
	for (temp =0 ;temp<SIZE ;temp++){
		printf("%d\t",array[temp]);
	}
	
}

void static SortArrayInAscendingOrder(void)
{
	char temp1,temp2;
	int var;
	for (temp1 = SIZE-1 ; temp1>=0 ; temp1--){
		for (temp2 =0 ;temp2<temp1 ;temp2++){
			if (array[temp1] < array[temp2]){
				var = array[temp1];
				array[temp1]	=  array[temp2];
				array[temp2]	= var;	
			}
		}	
		
	}


}


static void SortArrayInDescendingOrder(void)
{
	char temp1,temp2;
	int var;
	for (temp1 = SIZE-1 ; temp1>=0 ; temp1--){
		for (temp2 =0 ;temp2<temp1 ;temp2++){
			if (array[temp1] > array[temp2]){
				var = array[temp1];
				array[temp1]	=  array[temp2];
				array[temp2]	= var;	
			}
		}	
		
	}
	PrintArray();
}

static void DispSumOfOddVal(void)
{
	char index;
	int sum = 0 ;
	for (index =0 ;index<SIZE ;index++){
		if (( array[index]%2 )  != 0){
				sum += array[index];
	   }
	}
	printf("sum of odd values of Array is : %d\n",sum);	
}


static void DispSomeOfEvenVal(void)
{
	int sum = 0 ;
	char index;
	for (index =0 ;index<SIZE ;index++){
		if (( array[index]%2 )  == 0){
				sum += array[index];
	   }
	}
	printf("sum of Even values of Array is : %d\n",sum);	
}

static void SetOddClrEvenbit(void)
{
	char index;
	int sum = 0 ;
	for (index =0 ;index<SIZE ;index++){
		if (( index%2 )  != 0){
			array[index] |= 0xFF;	//if index odd set all bits
	   }else if( (index%2) == 0 )
			array[index] &= 0x00;   //if index even clear all bits

	}
	PrintArray();
}


