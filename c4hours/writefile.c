#include<stdio.h>
int main(){
    FILE * fpointer = fopen("employees.txt","w");
    fprintf(fpointer,"fuck you,liam\nnoel,fuckyou");
    fclose(fpointer);
    return 0 ;
}