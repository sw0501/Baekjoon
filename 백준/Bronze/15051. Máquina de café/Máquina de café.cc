#include<iostream>
#include<cmath>

using namespace std;

int main(){
    
    int a,b,c;
    cin >> a >> b >> c;
    
    int ans = 10000000000;
    
    int A = b*2 + c*4;
    int B = a*2 + c*2;
    int C = b*2 + a*4;
    
    cout << min(A,min(B,C));
    return 0;
}