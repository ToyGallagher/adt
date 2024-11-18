/*#include <stdio.h>

int main(){
   int secretnumber = 5;
   int guess;
   int guesscount = 0;
   int guesslimit=3;
   int outofguess = 0;

   while(guess != secretnumber && outofguess==0  ){
    if(guesscount<guesslimit){
        printf("Enter a number : ");
        scanf("%d",&guess);
        guesscount++; 
    } else{
    outofguess=1;
      }
    }
    if(outofguess==1){ 
        printf("out of guess");
    }else{ 
        printf("you win");
    }

   
   
}*/

/* ex 2 */
#include <stdio.h>
int main(){
   int secretnumber = 5;
   int guess;
   int guesscount = 0;
   int guesslimit=3;
   int outofguess = 0;
   while(guess!=secretnumber && guesscount!=guesslimit){
    if(guesscount<guesslimit){
        printf("Enter a number : ");
        scanf("%d",&guess);
        guesscount+=1;
        }
    }
    if(guess == secretnumber){
        printf("you win");
    }else{
        printf("noob");
    }
 }