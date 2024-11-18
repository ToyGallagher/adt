#include <stdio.h>

int main(){
    int num;
    int i;
    int fac=1;

    printf("Enter a number : ");
    scanf("%d",&num);
    for (i=1;i<=num;i++){
        fac=fac*i;
        printf("%d ",i);
    }
    
    printf("\nyour number is %d factorial is %d",num,fac );
    return 0;
}