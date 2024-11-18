#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getIn(char **x){
  int a;
  *x=(char *)malloc(sizeof(char));

  int i=0;
  while((a = getchar()) != '\n'){
    *x=(char *)realloc(*x,strlen(*x)+1);
    (*x)[i]=(char)a;
    i++;
  }
  (*x)[i]='\0';
}

int main(){ 
  char *x=NULL,*y=NULL,*res=NULL;

  getIn(&x);
  getIn(&y);
  res=(char *)malloc(sizeof(char)*(strlen(x)+1));

  //swap
  if(strlen(x)<strlen(y)){
    char *temp;
    temp=x;
    x=y;
    y=temp;
  }

  //plus
  int tod=0,a,i;
  
  for(i=0;i<=strlen(x);i++){
    if(i<strlen(y)){
      a=(int)x[strlen(x)-i-1]+(int)y[strlen(y)-i-1]+tod-96;
      //printf("%d\n",(int)x[3]-48);
      res[i]=(char)(48+(a%10));
      tod=a/10;
    }
    else if(i>=strlen(y) && i<strlen(x)){
      a=(int)x[strlen(x)-i-1]+tod-48;
      res[i]=(char)(48+(a%10));
      tod=a/10;
    }

    else if(tod!=0){
      res[i]=(char)(48+tod);
    }
    
  }

  for(i=strlen(res)-1;i>=0;i--){
    printf("%c",res[i]);
  }

  free(res);
  free(x);
  free(y);
  
  return 0;
}