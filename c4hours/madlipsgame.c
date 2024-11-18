#include<stdio.h>
int main(){
    char color[20];
    char pluralnoun[20];
    char celebrityF[20];
    char celebrityL[20];

    printf("enter a color : ");
    scanf("%s",color);
    printf("enter a pluralnoun : ");
    scanf("%s",pluralnoun);
    printf("enter a celebrity : ");
    scanf("%s%s",celebrityF,celebrityL);
    
    printf("Roses are %s\n",color);
    printf("%s are blue\n",pluralnoun);
    printf("I love %s %s\n",celebrityF,celebrityL);
    return 0;
} 