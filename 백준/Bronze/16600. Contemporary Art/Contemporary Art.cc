#include<iostream>
#include<cmath>
#include<stdio.h>

using namespace std;

int main(){
    
    long long int a;
    cin >> a;
    
    double b = sqrt(a);
    
    printf("%.8lf",b*4);
    
    return 0;
}