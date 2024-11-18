/*#include <stdio.h>
#include <stdbool.h>

bool is_prime(int number) {

    if (number <= 1) {
        return false;
    }
    
    for (int i = 2; i*i < number; i++)
    {
        if (number%i == 0)
        {
            return false;
        }
    }
    return true ;
}
int main(){
    int number;
    scanf("%d",&number);
    if (is_prime(number))
    {
        printf("1");
    }else{
        printf("0");
    }
    return 0 ;
}
//O(sqrt(n))
*/


