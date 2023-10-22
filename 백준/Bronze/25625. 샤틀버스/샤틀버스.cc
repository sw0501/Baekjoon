#include<iostream>

using namespace std;

int main(){
    
    int x,y;
    cin >> x >> y;
    
    if(x<=y){
        cout << y-x;
    }
    else{
        cout << x+y;
    }
    
    
    return 0;
}