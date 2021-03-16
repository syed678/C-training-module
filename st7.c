/*  Structure variables with and without a typedef   */

/*typedef  :-allow users to provide alternative names for data types*/
#include<stdio.h>
struct Point{
  int x;
  int y;
};

struct tPoint{
  int a;
  int b;
};




int main() {
    struct Point p1;
    puts("without typrdef");
    p1.x = 1;
    p1.y = 3;
    printf("%d \n", p1.x);
    printf("%d \n", p1.y);
   
   
	typedef struct tPoint type;
    puts("with typrdef");
	type p2;
    p2.a = 10;
    p2.b = 30;
    printf("%d \n", p2.a);
    printf("%d \n", p2.b);
   
   
   
   
    return 0;
}
