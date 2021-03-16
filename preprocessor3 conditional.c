/*The conditional directives are:*/
/*
#ifdef - If this macro is defined

#ifndef - If this macro is not defined

#if - Test if a compile time condition is true

#else - The alternative for #if

#elif - #else an #if in one statement

#endif - End preprocessor conditional*/


 
 
 #include<stdio.h> 
 #define COMPUTER "An amazing device\n"
 #define SLS "System level Solution"
 void main() 
 {
	 #if 0
	 printf( "Hello!\n" );
	 #elif 1
	 printf( "Hii!\n" );
	 #endif 	
	 
	 #ifndef COMPUTER
	 printf(COMPUTER);
	 #endif
	 #ifdef SLS
   	printf(SLS);
  	#endif
	 return ;


 
 }
  
