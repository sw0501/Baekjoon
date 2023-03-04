#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    
    int X,Y;
    cin >> X >> Y;
    
    int N;
    cin >> N;
    
    int a,b;
    
    for(int i=0;i<N;i++){
        cin >> a >> b;
        if((double)X/Y > (double)a/b){
            Y = b;
            X = a;
        }
    }
    
    printf("%.2lf",(double)X/Y*1000);
    
    return 0;
}