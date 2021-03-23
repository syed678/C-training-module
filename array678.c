/*
Perform the following operations on integer array of 10 elements.
 Accept the values from user.
 Sort an array in ascending order.
 Sort an array in descending order.
 Display sum of all odd values stored in an array.
 Display number of even values stored in an array.
 Set bits of odd position elements and clear bits of even position elements
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Fun.c"   //containing int float input function

#define SIZE 10

void SortArrayInAscendingOrder(void);
void SortArrayInDescendingOrder(void);
void  PrintArray(void);
void DispSumOfOddVal(void);
void DispSomeOfEvenVal(void);
void SetBitOfOddPos(void);	
void SetOddClrEvenbit(void);

static int array[SIZE];
main()
{
	char   temp = 0;
	char Arrint[2];
	int choice = 0;
	printf("enter 10 int\n");
	int wrongChoice = 0;
	for( temp = 0 ; temp<SIZE ; temp++){
				printf("\nEnter max 10 digit number : "); 
					array[temp] = EnterInt();
		
	}
	PrintArray();
	
	while(1)
	{
		printf("enter your choice\n");
		printf("\n1 : Sort an array in ascending order\n2 : Sort an array in descending order  ");
		printf("\n3 : Display sum of all odd values stored in an array\n4 : Display number of even values stored in an array");
		printf("\n5 : Set bits of odd position elements clear bits of even position elements");
		printf("\n6 : to EXIT\n");
		printf("enter your choice :  ");
		choice = Enterdigit();
	
		switch (choice){
		case 1 : 
			SortArrayInAscendingOrder();
			wrongChoice = 0;
		break;
		case 2 : 
			SortArrayInDescendingOrder();
			wrongChoice = 0;
		break;
		case 3 : 
			DispSumOfOddVal();
			wrongChoice = 0;
		break;
		case 4 : 
			DispSomeOfEvenVal();
			wrongChoice = 0;
		break;	
		case 5 : 
			SetOddClrEvenbit();
			wrongChoice = 0;
		break;
	
		case 6 : wrongChoice = 0;
			return;
		break;
		default : wrongChoice++;
				 printf("wrong choice enterd\n");
		}
	if( wrongChoice >= 3 ){
				puts("Multiple time wrong entries ....");	
				wrongChoice = 0;
				return ;
			}
	}			
}


 void  PrintArray(void)
{
	char temp;
	printf("now array : ");
	for (temp =0 ;temp<SIZE ;temp++){
		printf("%d\t",array[temp]);
	}
}

void  SortArrayInAscendingOrder(void)
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
	PrintArray();
}


 void SortArrayInDescendingOrder(void)
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

 void DispSumOfOddVal(void)
{
	char index;
	int sum = 0 ;
	for (index = 1 ;index<SIZE ;index += 2  ){
				sum += array[index];
	}
	printf("sum of odd values of Array is : %d\n",sum);	
}


void DispSomeOfEvenVal(void)
{
	int sum = 0 ;
	char index;
	for (index = 0 ;index<SIZE ;index += 2 ){
					sum += array[index];
	   
	}
	printf("sum of Even values of Array is : %d\n",sum);	
}


void print_binnary (int k)
{
	int c;
  for (c = 31; c >= 0; c--)
  {
    printf("%d",( k>>c ) & 1);
	if( c%8 == 0 ) printf("    ");
  }

  printf("\n");
	
}


 void SetOddClrEvenbit(void)
{
	char index;
	int sum = 0 ;
	int BitNo = 0;
	puts("Enter Bit no u want to set in Odd & Clear in Even : ");
	BitNo = EnterInt();
	for (index =0 ;index<SIZE ;index++){
		printf("\n%d\t",array[index]);	
		print_binnary( array[index] );
		
	}
	
	for (index =0 ;index<SIZE ;index++){
		if (( index%2 )  != 0){
		
			array[index] |= ( 1 << BitNo );	//if index odd set all bits
	   }else {
	   		array[index] &= ~(1 << BitNo);  //if index even clear all bits
	   }
	}

	for (index =0 ;index<SIZE ;index++){
		printf("\n%d\t",array[index]);	
		print_binnary( array[index] );
		
	}
//	PrintArray();
}


