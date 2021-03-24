//  E:\Local\Desktop\update\array\Fun.c
#include<stdlib.h> // because using exit  function
#include<string.h>

char CheckarrtoInt(char*p)
{	//check int value valid or not
	int i = 0;
	if(strlen(p) > 11 || p[0] == '\0') 
		return 0;
	if(p[0] == '-')
		i = 1;
	for(;i<11;i++){
		if(  ( isdigit(p[i]) || p[i] == 0) )
			continue;
			else
			 return 0;
	}	
	return 1;
}


int EnterInt(void)
{
	int errorCnt = 1;
	char arrint[11]={0};

	do{		
		gets(arrint);
		if(  CheckarrtoInt( arrint )){
				errorCnt = 0;
				return( atoi( arrint ) );
		}
		else{
				errorCnt += 1;
				if( errorCnt > 3 ){
					puts("Multiple time wrong entries ....");	
					memset(arrint,0,11);
					exit(0);
				}
					
				puts("enter valid value Enter Again :");
		}
	}while( errorCnt != 0 );
}





/////////////////////////////////////////////////////////////////////////////////////////////////////////////

char CheckarrtoFloat(char*p)
{	//check int value valid or not
	int i;
	int pointcnt = 0;
	for(i=0;i<10;i++){
		if ( isdigit(p[i]) || p[i] == 0 || p[i] == '.') {
			if ( p[i] == '.') 	pointcnt++;
		}
		else{
			return 0;	
		}
		if(pointcnt > 1 ) 	return 0;
					 
	}	
	return 1;
}

float EnterFloat(void)
{
	int errorCnt = 1;
	char arrfloat[10]={0};
	
	do{
		
		gets( arrfloat );
		if(  CheckarrtoFloat( arrfloat )){
				errorCnt = 0;
				return( atof( arrfloat ) );
		}
		else{
		errorCnt += 1;
		memset(arrfloat,0,10);
		if( errorCnt > 3 ){
			puts("3 time wrong entries ....");	
			errorCnt = 0;
			exit(0);
			}
		puts("enter valid value Enter Again :");
		}
		
	}while( errorCnt != 0 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Enterdigit(void)
{
	int errorCnt=1;
	char arrdigit[2]={0};
	
	do{
		gets(arrdigit);
		if(   isdigit(arrdigit[0]) && arrdigit[1] == 0 ){
				errorCnt = 0;
				return( atoi( arrdigit ) );
		}
		else{
				errorCnt += 1;
				memset(arrdigit,0,2);
				if( errorCnt > 3 ){
					puts("3 time wrong entries ....");	
					exit(0);
				}
				puts("enter valid value Enter Again :");
			}
		
	}while(errorCnt != 0);
	
}

char CheckName (char *p)
{
	int i;
	for(i= 0 ; p[i]; i++ ){
	
		if( !  ( ( isalpha(p[i]) ) || p[i] == ' ' || p[i] == 0) ||  ( p[i] == ' ' && p[i+1] == ' ') ) 
			return 0;
		}
	return 1;
}

/*
int Checkarrtodigit(char*p)
{	//check int value valid or not
	int i = 0;
	if(strlen(p) > 2) 
		return 0;

	if(  ( isdigit(p[0]) || p[1] == 0) )
		return 1;
		else
		 return 0;
	
	
}
*/
