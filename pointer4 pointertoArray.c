/*  pointer of array   */
//Syntax -> data_type (*var_name)[size_of_array];
#include<stdio.h> 
  
int main() 
{ 
    int arr[] = { 3, 5, 6, 7, 9 }; 
    int *p = arr; 
    int (*ptr)[5] = &arr; //ptr [0] pointing to 5 elements ptr [0][0] means 3
      
    printf("p = %p\t ptr = %p\n", p, ptr); 	//bese address for both
    printf("*p = %d\t\t\t *ptr = %p\n", *p, *ptr);  // 3 & base address of array
      
    printf("sizeof(p) = %lu\t\t sizeof(*p) = %lu\n", 
                          sizeof(p), sizeof(*p));  //8 byte becuuse its pointer
    printf("sizeof(ptr) = %lu\t\t sizeof(*ptr) = %lu\n",  
                        sizeof(ptr), sizeof(*ptr));  // 8 and 20 one is pointing to 5 int 4*5 =20
    return 0; 
}
