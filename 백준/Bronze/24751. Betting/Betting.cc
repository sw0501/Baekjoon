#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    printf("%.10lf\n",1/(double)N * 100);
    printf("%.10lf",1/(100-(double)N) * 100);
    
    return 0;
}