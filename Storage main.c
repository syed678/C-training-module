/*Static and Extern variable*/

#include <stdio.h>
//#include"storage1 fun.c"
extern void fun ( void );// means this func defination available in other file "storahge1 fun" but we are calling this fun in this file
static void fun2(void); // cant access out side of file

static int svar = 8;  //ccan access only n file in another file can not access
int gvar = 10; // global variable

int main() {
 
   static int sfv = 1000;	//static fun variable can not accces out side of fun

   printf("The value of local static var of  variable in main: %d\n", sfv); //
   printf("The value of static variable in main : %d\n",svar);
   svar += 10;
   printf("The value of static variable in main : %d\n",svar);
   fun();
   fun2();
   return 0;
}

static void fun2( void )
{
  printf("globle variable in same file fun2 after before  =%d \n",gvar);
  gvar += 11 ;	
  printf("globle variable in same file fun2 after update  =%d \n",gvar);
  svar += 10;
  printf("The value of globle static variable update in other fun2 : %d\n",svar);
}


