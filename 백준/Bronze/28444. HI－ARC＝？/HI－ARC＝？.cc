#include<iostream>

using namespace std;

int main(){
    
    int H,I,A,R,C;
    cin >> H >> I >> A >> R >> C;
    
    int a = H*I;
    int b = A*R*C;
    cout << a - b << "\n";
}