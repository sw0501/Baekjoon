#include<iostream>

using namespace std;

int main(){
    
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    if(a*b==c*d){
        cout << "E";
    }
    else{
        cout << (a*b>c*d?"M":"P");
    }
    
    
    return 0;
}