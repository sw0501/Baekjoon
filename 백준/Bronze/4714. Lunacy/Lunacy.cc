#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    
    while(1){
        double a;
        cin >> a;
        if(a==-1)break;
        cout << "Objects weighing ";
        printf("%.2lf ",a);
        cout << "on Earth will weigh ";
        printf("%.2lf ",a*0.167);
        cout << "on the moon.\n";
        
    }
    
    
    return 0;
}