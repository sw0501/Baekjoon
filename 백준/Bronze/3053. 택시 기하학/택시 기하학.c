#include<stdio.h>
#include<math.h>

int main(){
    
    const double pi = acos(-1.0);
    double r;
    scanf("%lf",&r);
    printf("%.6lf\n%.6lf",r*r*pi,r*r*2);
    
    
    return 0;
}