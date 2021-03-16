
/*function pointer example*/
/*function pointer point to function or hold address of function*/
#include <stdio.h> 
void add(int a, int b) 
{ 
    printf("Addition is %d\n", a+b); 
} 
void subtract(int a, int b) 
{ 
    printf("Subtraction is %d\n", a-b); 
} 
void multiply(int a, int b) 
{ 
    printf("Multiplication is %d\n", a*b); 
} 
 
void fun(int a) 
{ 
    printf("paased by function pointerValue of a is %d\n", a); 
} 
  
int main() 
{ 
    // fun_ptr_arr is an array of function pointers 
   char Arrint[2]={0};
   void (*fun_ptr)(int) = fun;  // & pointer should contain same return type and same formal arguments type like a function
  
    fun_ptr(10);  // * function will receive as 10 
   
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply}; 
    unsigned int ch, a = 100, b = 10; 
LABEL:
  	printf("value for a & b is 100 & 10\n");
    printf("Enter Choice: 1 for add, 2 for subtract and 3 "
            "for multiply\n"); 
    //scanf("%d", &ch);
	scanf("%s",Arrint);
	if( checkInt(Arrint) ){
	    ch =   Arrint[0] -48  ;
		}
		else{
			puts("Invalid Entery");
			goto LABEL;
		} 
  
    if (ch > 3 || ch <1) return 0; 
  
    (*fun_ptr_arr[ch-1])(a, b); 
  
    return 0; 
} 

int checkInt(char*p)
{	//here checking char for 0to 10 or not
	if(  ( p[0] >= '0' && p[0] <= 10) || p[1] == 0 )
			return 1;
			else
			 return 0;
			
}

