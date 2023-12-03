#include<iostream>
#include<stdio.h>


using namespace std;

int main(){
    
    while(1){
        double n;
        cin >> n;
        if(n==0)break;
        
        double ans = 1;
        
        //아내
        double temp = n;
        ans += temp;
        
        //자루
        temp *= n;
        ans += temp;
        
        //고양이
        temp *= n;
        ans += temp;
        
        //아기고양이
        temp *= n;
        ans += temp;
        
        printf("%.2lf\n",ans);
    }
    
    return 0;
}