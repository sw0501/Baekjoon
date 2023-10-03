#include<iostream>

using namespace std;

int main(){
    
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a==b&&b==c){
        cout << 2;
    }
    else {
        if(b>=a&&b>=c){
            if(b*b==a*a+c*c)cout << 1;
            else cout << 0;
        }
        else if(a>=b&&a>=c){
            if(a*a==b*b+c*c)cout << 1;
            else cout << 0;
        }
        else if(c>=a&&c>=b){
            if(c*c==a*a+b*b)cout << 1;
            else cout << 0;
        }
    }
    
    return 0;
}