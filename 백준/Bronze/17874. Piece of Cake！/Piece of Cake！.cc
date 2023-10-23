#include<iostream>

using namespace std;

int main(){
    
    int N,x,y;
    
    cin >> N >> x >> y;
    
    x = (x>N-x?x:N-x);
    y = (y>N-y?y:N-y);
    
    cout << x*y * 4;
    
    return 0;
}