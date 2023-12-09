#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;

int main(){
    
    int w,h;
    cin >> w >> h;
    
    double c = sqrt(w*w + h*h);
    
    printf("%.6lf",(w+h)-c);
    
    return 0;
}
