/*There is one AC room and we have to control it's cooling on some parameters. Display Control mode,
cooling temperature, Table selected (if any). Let's consider that we have to design logic as below
AC control mode (Input taken from user)
? 0-Manual mode
? 1-Open loop mode
? 2-Closed loop mode
Parameters
? Temperature range as input: 0-100
? Cooling range as output : 0-100

2.11.1 AC control mode = 0 (Manual mode)
? Set the Cooling range as per user requirement. (Take input from user)
? Minimum value of Cooling range should be 20.
? Maximum value of Cooling range should be 100.


2.11.2 AC control mode = 1 (Open loop mode)
? Temperature range as input. (Take input from user)
? Cooling range = Thermal equation
? Minimum value of Cooling range should be 20.
? Maximum value of Cooling range should be 100.



2.11.3 AC control mode = 2 (Closed loop mode)
? Cooling range as per user requirement. (Take input from user)
? Thermal range as per thermal equation. (Take input from user for temperature input)
? Cooling range is maximum of all (Cooling range, Thermal range, Minimum Cooling range).
? Minimum value of Cooling range should be 20.
? Maximum value of Cooling range should be 100.
Thermal Equation: ax2+bx+c, where x = Temperature input.
Relation between Temperature and a,b,*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MINTEMPRANGE  0 
#define MAXTEMPRANGE  100 
#define MINCOOL  20 
#define MAXCOOL  100 

static int checkdigit(char*p);
static int CheckarrtoInt(char*p);
static int EnterInt(void);
static int CheckarrtoFloat(char*);
static float EnterFloat(void);
static void ManualMode ( void );
static void OpenloopMode( void );
static void ClosedloopMode( void );

int MinTemp,MaxTemp;
int MinCool, MaxCool;
float coolmode2;

main()
{
	char Arrint[2];
	int choice = 0;
	int errorCount = 1 ;
	while(1)	
	{
		puts("\n\t......................In Room......................");
		puts(" 1 : Manual mode \t 2 : Open loop Mode \t 3 :Closed loop mode \t 9 : EXIT");
		LABEL :
			if( errorCount > 3 ){
				puts("Multiple time wrong entries ....");	
				errorCount = 0;
				exit(0);
			}
			printf("enter your choice :  ");
			scanf("%s",Arrint);
			if( checkdigit(Arrint) ){
		    choice =   Arrint[0] -48;
			}
			else{
				puts("Invalid Entery");
				errorCount += 1;
				goto LABEL;
				
			}
		
		switch (choice){
			case 1 : 
				ManualMode();
				printf("\nIn Manual mode ...\n");	
			break;
			case 2 : 
				OpenloopMode();
				printf("\nIn Openloop Mode ...\n");
			break;
			case 3 : 
				ClosedloopMode();
					printf("\nIn Closed loop Mode ...\n");
			break;
			
			case 9 : 
				return;
			break;
			default : puts("Invalid Entery");
					 errorCount += 1;
			}		
	}	
}



static void ManualMode ( void )
{	
	
	puts("Minimum Cooling range : 20 \t Maximum  Cooling range : 100\n");
	//puts("Enter cooling range you want");
	int errorCount = 0;
	L1: 
		puts("enter Minimum cooling range"); 
		MinCool = EnterInt();
	
		if( MinCool <= MINCOOL || MinCool > ( MAXCOOL-1 ) ){
			puts("In this mode minimum cooling value is 20\t maximum cooling value is 100  ");
			errorCount++;
			if(errorCount > 3){
					puts("4 time wrong entries ....");	
					errorCount = 0;
					exit(0);
				}
			goto L1;
		}
		
	errorCount = 0;	
		
	L2:printf("entered Minimum cooling value is : %d \n",MinCool); 
		puts("enter Max cooling range"); 
		MaxCool = EnterInt();
		if( MaxCool <= MinCool || MaxCool > MAXCOOL ){
			puts("In this mode Max cooling value is 100  Enter valid value");	
			errorCount++;
			if(errorCount > 3){
					puts("3 time wrong entries ....");	
					errorCount = 0;
					exit(0);
				}
			goto L2;
		}
		printf(" your Colling range is %d to\t %d  ...",MinCool,MaxCool);
}


static void OpenloopMode( void )
{
	//equation temp (  ax^2 + bx +c )
	int errorcnt = 1;
	float x;
	float a,b ,c;
L2:	if(errorcnt > 3){
					puts("Multiple time wrong entries ....");	
					errorcnt = 0;
					exit(0);
				}
	
	puts("Minimum Cooling range : 20 \t Maximum  Cooling range : 100");
	int errorCount = 0;
	puts("enter temprature for cooling range"); 
	x = EnterFloat();
	if( x < 0 || x > 100){
		puts("enter valid tempreture...\n");
		goto L2;
	}
	if(x >= 0 && x < 26 ){
		a = 0.0202;
		b = -0.3345;
		c= 15.363;
	}
	else if(x > 25 && x < 51 ){
		a = 0;
		b = 0;
		c= 80;
	}
	else if(x > 50 && x < 76 ){
		a = 0.0202;
		b = -0.3345;
		c= 45.363;
	}
	else {
		a = 0;
		b = 0;
		c= 100;
	}
			
 	coolmode2 =  ( a*x*x ) + ( b*x ) + c;	
	printf("cooling in open loop is  : %f \n", coolmode2);
	if( x < 25 || ( x > 60 && x < 75 ) )
	{
		puts("for cooling range enter temprature value between  : 26 - 60 or 75 - 100\n ");
		errorcnt += 1;
		goto L2;
	}
}

static void ClosedloopMode( void )
{
	int errorcnt = 1;
L3:	OpenloopMode();
	ManualMode();	
	if( MaxCool < coolmode2 ){
		printf("for this this temp cooling  greater than max cooling  " );
		puts("...enter values again");
		errorcnt += 1;
		goto L3;
	}
if(errorcnt > 3){
		puts("Multiple time wrong entries ....");	
		errorcnt = 0;
		exit(0);
	}
}

static int checkdigit(char*p)
{	//here checking char for 0to 10 or not
	if(  ( p[0] >= '0' && p[0] <= 10) || p[1] == 0 )
			return 1;
			else
			 return 0;
			
}

static int EnterInt(void)
{
	static int errorCnt=1;
	char arrint[10]={0};
	
	LAB1:memset(arrint,0,10);
		scanf("%s",arrint);
		if(  CheckarrtoInt( arrint )){
				errorCnt = 0;
				return( atoi( arrint ) );
		}
		else{
				errorCnt += 1;
				if( errorCnt > 3 ){
					puts("3 time wrong entries ....");	
					errorCnt = 0;
					exit(0);
				}
					
				puts("enter valid value Enter Again :");
				goto LAB1;	
				
		}
}

static int CheckarrtoInt(char*p)
{	//check int value valid or not
	int i;
	for(i=0;i<10;i++){
		if(  ( isdigit(p[i]) || p[i] == 0) )
			continue;
			else
			 return 0;
			
	}	
	return 1;
}



static int CheckarrtoFloat(char*p)
{	//check int value valid or not
	int i;
	int pointcnt = 0;
	for(i=0;i<10;i++){
		if ( isdigit(p[i]) || p[i] == 0 || p[i] == '.') {
			if ( p[i] == '.'){
				pointcnt++;
				if(pointcnt > 1 )
					return 0;
			}
			continue;
		}
		else{
		return 0;	
		}
			 
			
	}	
	return 1;
}

static float EnterFloat(void)
{
	static int errorCnt=1;
	char arrfloat[10]={0};
	
	LAB1:memset(arrfloat,0,10);
		scanf("%s",arrfloat);
		if(  CheckarrtoFloat( arrfloat )){
				errorCnt = 0;
				return( atof( arrfloat ) );
		}
		else{
				errorCnt += 1;
				if( errorCnt > 3 ){
					puts("3 time wrong entries ....");	
					errorCnt = 0;
					exit(0);
				}
					
				puts("enter valid value Enter Again :");
				goto LAB1;	
				
		}
}


