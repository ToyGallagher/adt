/*#include<stdio.h>
int findfactorial(int num){
    int i =1;
    int factorial = 1;
    for ( i = 1; i <= num; i++)
    {
        factorial *= i  ;
    }
    //printf("%d",factorial);
    return factorial ;
}
int strongnumber(int num){
    int result = num;
    int sum = 0;
    while (result>0)
    {
        int x = result%10;
        sum += findfactorial(x);
        result /= 10;
    }
    return (sum == num);
}
int main(){
    int n , m ;
    scanf("%d",&n);
    if (n>0 && n<=100000)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&m);
            if (m>0 && m<= 1000000)
            {
                int lastresult = 0;
                for (int j = 1;j<=m ; j++)
                {
                    if (strongnumber(j) &&  j<m)
                    {
                        lastresult = j;
                    }
                }
                printf("%d\n",lastresult);
            }else{
                break;
            } 
        }   
    }
}*/
/*
#include<stdio.h>
void inttoroman(int num) {
    char* romanSymbols[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",  "XL", "X",  "IX", "V",  "IV", "I"};
    int romanValues[] =    {1000, 900,  500,  400,  100,  90,   50,   40,   10,   9,    5,    4,    1};
    int i = 0 ;
    while (num>0)
    {
        if (num>=romanValues[i])
        {
            printf("%s",romanSymbols[i]);
            num-=romanValues[i];
        }else{
            i+=1;
        }
        
    }
}
int main(){
    int n,num;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&num);
        inttoroman(num);
        printf("\n");
    }
    return 0;
}*/

#include<stdio.h>

int checkLeapYear(int year){
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else{
        return 0;
    }
}

int getday(int month ,int year){
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month = 2 && checkLeapYear(year))
    {
        return 29;
    }else{
        return days[month - 1];
    }
    
}

const char* getmonth(int month){
    const char* months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    return months[month-1];
}
void printca(int month,int year){
    int start = 1;
    printf("====================\n");
    printf("%s %d\n",getmonth(month),year);
    printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    for (int y = 1990; y <year ; y++)
    {
        start += checkLeapYear(y) ? 366 :365;
    }
    for (int m = 1; m < month; m++)
    {
        start+=getday(m,year);
    }
    start %= 7;
    

    
    int days = 1;
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            if(i==0 && j<start){
                printf("    ");
      }

      else if(days<10){
        printf("  %d ",days);
        days++;
      }

      else if(days>=10 && days<=getday(month,year)){
        printf(" %d ",days);
        days++;
      }

      else {
        printf("    ");
      }

    }
    printf("\n");
  }
}

int main(){
    int year ,month;
    printf("Enter year: ");
    scanf("%d",&year);
    printf("Enter month: ");
    scanf("%d",&month);

    printca(month,year);
    return 0;
}

/*#include <stdio.h>

int main() {
    
    int size;
    char direction;
    scanf("%c %d",&direction,&size);

    int height = (size+1)*2;
    int width = (size*2)+1;
    char draw[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0;j<width;j++){
            draw[i][j] = ' ';
        }
    }
    for (int i = 0; i < size+1; i++)
    {
        for (int j = size-i; j < size-i +(2*i+1); j++)
        {
            draw[i][j] = '#';
        }
        
    }
    for (int i = size+1; i < height; i++)
    {
        for (int j = 1; j < width-1; j++)
        {
            draw[i][j] = '#';
        }
    }

    if (direction == 'N')
    {
        for(int i =0 ;i<height;i++){
            for(int j = 0;j<width;j++){
                printf("%c",draw[i][j]);
        }
        printf("\n");
        }   
    }
    if (direction == 'S')
    {
        for(int i = height-1 ; i >= 0 ; i--){
            for(int j = 0;j<width;j++){
                printf("%c",draw[i][j]);
        }
        printf("\n");
        }   
    }
    if (direction == 'E')
    {
        for(int i =0 ;i<width;i++){
            for(int j = height-1;j>=0;j--){
                printf("%c",draw[j][i]);
        }
        printf("\n");
        }   
    }
    if (direction == 'W')
    {
        for(int i =0 ;i<width;i++){
            for(int j = 0;j<height;j++){
                printf("%c",draw[j][i]);
        }
        printf("\n");
        }   
    }
    
    return 0;
}*/

#include <stdio.h>

int isLeapYear(int year) {
  if (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0)) {
    return 1;
  } else {
    return 0;
  }
}

const char *getMonthName(int month) {
  const char *months[] = {"January",   "February", "March",    "April",
                         "May",       "June",     "July",     "August",
                         "September", "October",  "November", "December"};

  return months[month - 1];
}



int getDay(int month, int year) {
  int dayammount[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
  if (month == 2 && isLeapYear(year)) {
    return 29;
  }
    
  else {
    return dayammount[month - 1];
  }
  
}

void printCa(int month, int year) {
  int day = 1;
  printf("====================\n");
  printf("%s %d\n", getMonthName(month), year);
  printf("Sun Mon Tue Wed Thu Fri Sat\n");

  //+year

  for (int i = 1900; i < year; i++) {
  //  printf("%d\n",isLeapYear(i));
    if (isLeapYear(i)) {
      day += 366;
    }

    else {
      day += 365;
    }
  }

  //+month

  for (int i = 1; i < month; i++) {
    day += getDay(i, year);
  }
  
  //print
  day%=7;
  int start=1;

  for(int i=0;i<6;i++){
    for(int j=0;j<7;j++){
      if(i==0 && j<day){
        printf("    ");
      }

      else if(start<10){
        printf("  %d ",start);
        start++;
      }

      else if(start>=10 && start<=getDay(month,year)){
        printf(" %d ",start);
        start++;
      }

      else {
        printf("    ");
      }

    }
    printf("\n");
  }
    
}

int main(void) {
  int year,month;

  printf("Enter year: ");
  scanf("%d",&year);
  printf("Enter month: ");
  scanf("%d",&month);
  
  printCa(month, year);

  return 0;
}