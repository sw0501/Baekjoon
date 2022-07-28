#include<iostream>

using namespace std;

int main(){
    
    int C;
    int A,B;
    cin >> C >> A >> B;
    
    int a,b;
    a = A/2;
    b = B;
    int ck = (C>a+b?a+b:C);
    
    cout << ck << "\n";
    
    
    return 0;
}