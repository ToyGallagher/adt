#include <stdio.h>
int main(){
    
    sayhi("toy",17);
    sayhi("liam",18);
    sayhi("noel",19);
    return 0 ;
}
void sayhi(char name[],int age){
    printf("hello %s %d\n",name,age);
}
