/*#include <stdio.h>
int main(){
    double num1;
    double num2;
    char op;

    printf("Enter a number1 : ");
    scanf("%lf", &num1);
    printf("Enter operator : ");
    scanf("%s", &op);
    
    printf("Enter a number2 : ");
    scanf("%lf", &num2);

    if(op == '+'){
        printf("%f",num1 + num2);
    }else if(op == '-'){
        printf("%f",num1 - num2);
    }else if(op == '/'){
        printf("%f",num1 / num2);
    }else if(op == '*'){
        printf("%f",num1 * num2);
    }else{
        printf("invalid operator");
    }

    return 0;
}*/
#include <stdio.h>
int main(){
    double num1;
    double num2;
    char op;

    printf("Enter anumber 1 : ");
    scanf("%lf",&num1);
    printf("Enter operator : ");
    scanf("%s",&op);
    printf("Enter anumber 2 : ");
    scanf("%lf",&num2); 

    if (op == '+')
    {
        printf("%f",num1+num2);
    } else if(op == '-'){
        printf("%f",num1-num2);
    } else if(op == '*'){
        printf("%f",num1*num2);
    } else{
        printf("invalid operator");
    }

    return 0;
}
