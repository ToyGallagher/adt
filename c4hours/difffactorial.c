#include <stdio.h>

int main(){
    int num1;
    int num2;
    int i;
    int j;
    int fac1=1;
    int fac2=1;
    int diff;

    printf("Enter a number1 : ");
    scanf("%d",&num1);
    printf("Enter a number2 : ");
    scanf("%d",&num2);

    for (i=1;i<=num1;i++){
        fac1=fac1*i;
    }
    for (i=1;i<=num2;i++){
        fac2=fac2*i;
    }
    diff=fac1-fac2;
    
    printf("\nyour number is %d factorial1 is %d factorial2 is %d the difference of factoril is %d",num1,fac1,fac2,diff );
    return 0;
}