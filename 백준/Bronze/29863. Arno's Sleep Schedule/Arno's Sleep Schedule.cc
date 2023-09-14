#include<iostream>

using namespace std;

int main(){
    
    int A,B;
    cin >> A >> B;
    
    if(A>=20 && A<=23){
        cout << B + 24 - A;
    }
    else {
        cout << B - A;
    }
    
    
    return 0;
}