#include<iostream>

using namespace std;

int main(){
    
    int A,B,C;
    cin >> A >> B >> C;
    
    if(A>=B && A >=C){
        cout << A-B + A-C;
    }
    else if(B>=A && B >=C){
        cout << B-A + B-C;
    }
    else if(C>=A && C >=B){
        cout << C-A + C-B;
    }
    
    return 0;
}