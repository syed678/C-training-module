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
#include"Fun.c"   //containing int float input function

#define SIZE 10

void SortArrayInAscendingOrder(void);
void SortArrayInDescendingOrder(void);
void  PrintArray(void);
void DispSumOfOddVal(void);
void DispEvenVal(void);
void SetBitOfOddPos(void);	
void SetOddClrEvenbit(void);

static unsigned int array[SIZE];
main()
{
	char   temp = 0;
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
		printf("\n\t............MENU............");
		printf("\n1 : Sort an array in ascending order\n2 : Sort an array in descending order  ");
		printf("\n3 : Display sum of all odd values stored in an array\n4 : Display number of even values stored in an array");
		printf("\n5 : Set bits of odd position elements clear bits of even position elements for perticular bit no");
		printf("\n6 : to EXIT\n");
		printf("\t==============================\n");
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
			DispEvenVal();
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
		printf("%lu\t",array[temp]);
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
	for (index = 0 ;index<SIZE ; index++  ){
			if (( array[index]%2 )  != 0){
				sum += array[index];
			}
	}
	printf("sum of odd values of Array is : %d\n",sum);	
}


void DispEvenVal(void)
{
	int sum = 0 ;
	char index;
	printf( "Even values in Array : \n" ) ;
	for (index =0 ; index<SIZE ;index++){
		if (( array[index]%2 )  == 0){
				printf(" %lu\n",array[index]);
	   }
	}
}


void print_binnary (int k)
{
  char c;
  for (c = 31; c >= 0; c--)
  {
    printf("%d",( k>>c ) & 1);
	if( c%8 == 0 ) {
		printf("    ");	
	}
  }

  printf("\n");	
}


 void SetOddClrEvenbit(void)
{
	char index;
	char BitNo = 0;
	char errorCnt =1;
	do{
		puts("Enter Bit no u want to set in Odd & Clear in Even : ");
		BitNo = EnterInt();
		if(BitNo >= 0 && BitNo <32)
		{
			errorCnt = 0;
		}
		else{
			puts("invalid Bit number entered");
			errorCnt++;	
		}	
	}while(errorCnt >0 && errorCnt < 4) ;
	if( errorCnt ){
			//if errorCnt not zero it will be more than 3
			puts("Multiple time wrong entries ....");	
			errorCnt = 0;
			return ;
		
	}
	
	for (index =0 ;index<SIZE ;index++){
		printf("\n%lu\t",array[index]);	
		print_binnary( array[index] );
		
	}
	
	for (index =0 ;index<SIZE ;index++){
		if ( index%2   != 0){
			array[index] |= ( 1 << BitNo );	//set bit
	   }else {
	   		array[index] &= ~(1 << BitNo);  //Clear bit
	   }
	}
	puts("Value After update :");
	for (index =0 ;index<SIZE ;index++){
		printf("\n%lu\t",array[index]);	
		print_binnary( array[index] );
		
	}
}


