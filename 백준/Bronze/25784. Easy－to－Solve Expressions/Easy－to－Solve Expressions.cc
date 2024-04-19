#include<iostream>

using namespace std;

int main(){
    
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a+b==c || b+c==a | a+c==b){
        cout << 1 << "\n";
    }
    else if(a*b==c||a*c==b||b*c==a){
        cout << 2 << "\n";
    }
    else{
        cout << 3 << "\n";
    }
    
    
    return 0;
}