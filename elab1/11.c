#include <stdio.h>
#include <string.h>
int main(){
    char a[100];
    char b[100];
    char c[100];
    printf("First sentence: ");
    fgets(a,100,stdin);
    printf("Second sentence: ");
    fgets(b,100,stdin);
    printf("Third sentence: ");
    fgets(c,100,stdin);
    printf("%zu",(strlen(a)+strlen(b)-2)*(strlen(c)-1));
    return 0;
}
