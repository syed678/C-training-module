//without pragma output will be  4 8 24 16  
// with pragma outpit will be    3 7 13 13
#pragma pack (1)
#include <stdio.h>
 
// Alignment requirements
// (typical 32 bit machine)
 
// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes
 
// structure A
typedef struct structa_tag
{
   char        c;
   short int   s;
   
} structa_t;
 
// structure B
typedef struct structb_tag
{
   short int   s;
   char        c;
   int         i;
} structb_t;
 
// structure C
typedef struct structc_tag
{
   char        c;
   double      d;
   int         s;
} structc_t;
 
// structure D
typedef struct structd_tag
{
   double      d;
   int         s;
   char        c;
} structd_t;
 
int main()
{
   printf("sizeof(structa_t) = %lu\n", sizeof(structa_t));//3
   printf("sizeof(structb_t) = %lu\n", sizeof(structb_t));//7
   printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));//13
   printf("sizeof(structd_t) = %lu\n", sizeof(structd_t));//13
 
   return 0;
}


