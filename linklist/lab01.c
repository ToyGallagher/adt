//1
/*#include<stdio.h>
int main(){
    int a,b,h;
    printf("a: ");
    scanf("%d",&a);
    printf("b: ");
    scanf("%d",&b);
    printf("h: ");
    scanf("%d",&h);
    float result = ((float)a+(float)b)*h/2;
    printf("Area is %.2f",result);
    return 0;
}*/

//2
/*#include <stdio.h>
int main(){
    int time,hour;
    int x,y,z;
    int result;
    scanf("%d %d",&time,&hour);
    if (time+hour <= 24)
    {
        z = 0;
        result = time+hour;
    }
    else{
        x = 24-time;
        y = hour-x;
        z = y/24+1;
        result = y%24;
    }
    printf("%d %d",z,result);
    return 0;
}*/

/*
//3
#include <stdio.h>
int main(){
    int time;
    int day;
    int hour;
    int minute;:
    int second;
    scanf("%d",&time);
    day = time/86400;
    hour = (time%86400)/3600;
    minute = ((time%86400)%3600)/60;
    second = (((time%86400)%3600)%60);
    printf("%d %d %d %d",day,hour,minute,second);
    return 0;
}
*/
//4
/*#include <stdio.h>
#include <stdlib.h>
int main() {
    char x,y;
    scanf("%c %c",&x,&y);
    printf("%d",abs(y-x));
    //printf("%c %c",x,y);
    return 0;
}*/
/*
//5
#include <stdio.h>
#include <math.h>
int main(){
    double x,y,z;
    char status1,status2;
    
    scanf("%lf %lf %lf\n",&x,&y,&z);
    int result = x;
    scanf("%c %c",&status1,&status2);
    if(status1 == 'Y' || status1 == 'y'){
        result += y;
    }
    if(status2 == 'Y' || status2 == 'y'){
        result = ceil(result/z);
    }
    printf("%d",result);
    return 0 ;
}*/

#include <stdio.h>

void loop_symbol(char symbol, int size) {
    for (int i = 0; i < size; i++) 
        printf("%c", symbol);
}

void one_line_detail(int space_size, int sharp_size) {
    loop_symbol(' ', space_size);
    loop_symbol('#', sharp_size);
    printf("\n");
}

void vertical_tail(int n) {
    int sharp = n * 2 - 1, line = n + 1;
    for (int i = 0; i < line; i++) 
        one_line_detail(1, sharp);
}

void vertical_top_head(int n) {
    int space = n, sharp = 1, line = n + 1;
    for (int i = 0; i < line; i++) {
        one_line_detail(space, sharp);
        space--;
        sharp += 2;
    }
}

void vertical_down_head(int n) {
    int space = 0, sharp = n * 2 + 1, line = n + 1;
    for (int i = 0; i < line; i++) {
        one_line_detail(space, sharp);
        space++;
        sharp -= 2;
    }

}

void horizontal_first_last_line(int space_size) {
    one_line_detail(space_size, 1);
}

void horizontal_main(int space_size, int sharp_size, int line_size) {
    int space = space_size, sharp = sharp_size;
    int top_part_line = line_size, bottom_part_line = line_size - 1;

    for (int i = 0; i < top_part_line; i++) 
        (space == 0) ? one_line_detail(0, sharp++) : one_line_detail(space--, sharp++);
    
    sharp = sharp - 2;
    if (space_size != 0) space = 1;
    for (int i = 0; i < bottom_part_line; i++)
        (space == 0) ? one_line_detail(0, sharp--) : one_line_detail(space++, sharp--);
}

int main() {
    char direction;
    int size;
    scanf("%c %d", &direction, &size);
    switch(direction) {
        case 'N': vertical_top_head(size);
                  vertical_tail(size);
                  break;

        case 'S': vertical_tail(size);
                  vertical_down_head(size);
                  break;

        case 'E': horizontal_first_last_line(size + 1);
                  horizontal_main(0, size + 3, size);
                  horizontal_first_last_line(size + 1);
                  break;

        case 'W': horizontal_first_last_line(size);
                  horizontal_main(size - 1, size + 3, size);
                  horizontal_first_last_line(size);
                  break;

        default:  break;
    }
    return 0;
}
