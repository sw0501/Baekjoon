#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int temp = N;
    
    int flag1 = 0;
    int flag2 = 0;
    while(temp!=0){
        if(temp%10 == 7)flag1 = 1;
        temp/=10;
    }
    
    if(N%7==0)flag2 = 1;
    
    if(flag1&&flag2){
        cout << 3;
    }
    else if(flag1&&!flag2){
        cout << 2;
    }
    else if(!flag1&&flag2){
        cout << 1;
    }
    else if(!flag1&&!flag2){
        cout << 0;
    }
    
    return 0;
}