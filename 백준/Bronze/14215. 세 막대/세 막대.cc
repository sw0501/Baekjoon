#include<iostream>
#include<cmath>

using namespace std;

int main(){
    
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a >= b && a>=c){
        if(a >= b + c ){
            a = b+c - 1;
        }
    }
    else if(b >= a && b>=c){
        if(b >= a + c ){
            b = a + c - 1;
        }
    }
    else if(c>=a && c>=b){
        if(c >= a + b ){
            c = a + b - 1;
        }
    }
    
    cout << a + b + c << "\n";
    
    return 0;
}