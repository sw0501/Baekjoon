#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
    double n;
    
    cin >> n;
    
    double m = 25 + n * 0.01;
    if (m <= 100){
        m = 100;
    }
    else if(m>=2000){
        m = 2000;
    }
    
    printf("%.2lf",m);
    return 0;
}