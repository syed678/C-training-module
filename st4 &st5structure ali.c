//without pragma output will be  4 8 24 16  
// with pragma output will be    3 7 13 13

#include <stdio.h>
// structure A
#pragma pack (1)
typedef struct structa_tag
{
   char        c;
   short int   s;

} structa_t;
 #pragma pack (0)
// structure B
typedef struct structb_tag
{
   short int   s;
   char        c;
   int         i;
} structb_t;
 #pragma pack ()
// structure C
typedef struct structc_tag
{
   char        c;	//8 but 7 holes
   double      d;	//8 byte
   int         s;	// 8 but 4 holes
} structc_t;
 
// structure D
#pragma pack (1)
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


