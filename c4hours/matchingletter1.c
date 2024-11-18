#include <stdio.h>

int main(){
    char c1[20];
    char c2[20];
    printf("Enter a char 1 : ");
    scanf("%s",c1);
    
    printf("Enter a char 2 : ");
    scanf("%s",c2);
    

    if(c1 == c2){
        printf("match");
    }else{
        printf("not match");
    }

    return 0 ;
}