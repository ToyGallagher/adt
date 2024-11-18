/*#include <stdio.h>
int main(){
    int num1,num2;
    printf("enter a number 1 : ");
    scanf("%d",&num1);
    printf("enter a number 2 : ");
    scanf("%d",&num2);
    printf("%d\n",num1+num2);
    printf("%d\n",num1-num2);
    printf("%d\n",num1*num2);
    printf("%d\n",num1/num2);
    printf("%d\n",num1%num2);
    return 0 ;
}*/

/*int main(){
    int a,b,c;
    int x;
    //int x[] = {a,b,c};
    printf("Enter a number : ");
    scanf("%d",&a);
    printf("Enter a number : ");
    scanf("%d",&b);
    printf("Enter a number : ");
    scanf("%d",&c);
    a=(2*pow(a,2))-a+3;
    b=(2*pow(b,2))-b+3;
    c=(2*pow(c,2))-c+3;
    printf("%d %d %d",a,b,c);
    return 0 ;
}*/

int main(){
    int i;
    int x;
    printf("Enter a number : ");
    scanf("%d",&i);
    x=(2*pow(i,2))-i+3;
    printf("your ans is %d\n",x);
    while (i!=0){
        printf("Enter a number : ");
        scanf("%d",&i);
        if(i==0){
            printf("end");
            break;}
        else{x=(2*pow(i,2))-i+3;
        printf("your ans is %d\n",x);}
        }
    
    
    /*a=(2*pow(a,2))-a+3;
    b=(2*pow(b,2))-b+3;
    c=(2*pow(c,2))-c+3;
    printf("%d %d %d",a,b,c);*/
    return 0 ;
}