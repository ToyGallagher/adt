#include <stdio.h>
#include <stdlib.h>
struct student{
    char name[50];
    char major[50];
    int age;
    double gpa;

};


int main(){
   struct student student1;
   student1.age = 17;
   student1.gpa = 3.5;
   strcpy(student1.name,"Toy");
   strcpy(student1.major,"business");


   struct student student2;
   student2.age = 99;
   student2.gpa = 6.5;
   strcpy(student2.name,"liam");
   strcpy(student2.major,"oasis");
   printf("%f\n",student1.gpa);
   printf("%s",student2.name);
    return 0 ;
}