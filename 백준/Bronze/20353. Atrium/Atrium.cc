#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;

int main(){
    
    long long int N;
    cin >> N;
    
    double ans = 4*sqrt(N);
    
    printf("%.8lf",ans);
    
    return 0;
}