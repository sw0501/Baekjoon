#include<iostream>

using namespace std;

int main(){
    
    int a,b,c;
    cin >> a >> b >> c;
    if(a>=b && b>=c || c>=b && b>=a){
        cout << b << "\n";
    }
    else if(a>=c && c>=b || b>=c && c>=a){
        cout << c << "\n";
    }
    else if(b>=a && a>=c || c>=a && a>=b){
        cout << a << "\n";
    }
    
    return 0;
}