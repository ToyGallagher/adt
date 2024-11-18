#include <stdio.h>
int main(){
    double width,length;
    printf("width : ");
    scanf("%lf",&width);
    printf("length : ");
    scanf("%lf",&length);

    printf("area : %lf\n",width*length);
    printf("perimeter : %lf",(2*width)+(2*length));
    return 0 ;

}