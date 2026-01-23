#include<iostream>

using namespace std;

int main(){
    
    int a,b;
    int c,d;
    
    cin >> a >> b >> c >> d;
    
    while(b>0 && d>0){
        b -= c;
        d -= a;
    }
    
    if(b<=0 && d<=0){
        cout << "DRAW" << "\n";
    }
    else if(b>0){
        cout << "PLAYER A" << "\n";
    }
    else{
        cout << "PLAYER B" << "\n";
    }
    
    return 0;
}