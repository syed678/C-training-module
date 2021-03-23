/*  Structure variables with and without a typedef   */

/*typedef  :-allow users to provide alternative names for data types*/
#include<stdio.h>
struct A{
  int x;
  int y;
};

struct B{
  int a;
  int b;
};
int main()
 {
    struct A p1;
    puts("without typrdef");
    p1.x = 1;
    p1.y = 3;
    printf("%d \n", p1.x);
    printf("%d \n", p1.y);
   
   	typedef struct B newtypename;	// now inplace of struct B , we can use newtypename
    puts("with typrdef");
	newtypename p2;
    p2.a = 10;
    p2.b = 30;
    printf("%d \n", p2.a);
    printf("%d \n", p2.b);
    return 0;
}
