#include <stdio.h>

int main(){
   int age = 30;
   int * pAge = &age;
   double gpa = 3.4;
   double * pGpa = &gpa;
   char grade = 'A';
   char *aGrade = &grade;

   printf("age is memory address: %p\n",pAge);
   printf("age is memory address: %p\n",age);
   printf("age is memory address: %p\n",&age);
   printf("age is memory address: %d\n",*pAge);
   printf("age is memory address: %d\n",*&age);
   
    return 0 ;
}