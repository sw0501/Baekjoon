#include<iostream>

using namespace std;

int main(){
    
    int a,b;
    int num;
    cin >> num;
    
    a = num;
    cin >> num;
    if(num>a){
        b = a;
        a = num;
    }
    else b = num;
    
    cin >> num;
    if(num>a){
        b = a;
        a= num;
    }
    else if(num>b){
        b = num;
    }
    
    cout << a+b;
    return 0;
}