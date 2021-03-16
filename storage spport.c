// function used in storage 1 var file here present
//its support file for file (main.c) file

#include<stdio.h>
extern int gvar;	//means define in other file but using in this file
void fun ( void )
{
 printf("...........This is extern fun call by main written in other file\n");
  printf("globle variable in other file fun after before  =%d \n",gvar);
  gvar += 99 ;	
  printf("globle variable in other file fun after update  =%d \n",gvar);
	
}
