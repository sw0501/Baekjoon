#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    
    double g = 3.785411784;
    double num;
    cin >> num;
    num *=1609.344;
    
    g = g / num * 100 * 1000;
    printf("%lf.2",g);
    
    
    
    return 0;
}