#include <stdio.h>
#define SIZE 101

int main(){
    int n,temp,max = 0;
    int numbers[SIZE];
    scanf("%d",&n);
    for (int i = 0; i < SIZE; i++){
        numbers[i]=0;
    }
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&temp);
        numbers[temp]++;
        //printf("%d ",numbers[temp]);
        if (numbers[temp]>max)
        {
            max = numbers[temp];
        }
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        if (numbers[i] == max)
        {
            printf("%d ",i);
        }
    }
    return 0;
} 
    
