#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        double d;
        double f,p;
        cin >> d >> f >> p;
        
        printf("$%.2lf\n",d*f*p);
    }
    
    return 0;
}