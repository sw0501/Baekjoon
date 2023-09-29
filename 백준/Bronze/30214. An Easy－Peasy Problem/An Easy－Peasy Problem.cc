#include<iostream>

using namespace std;

int main(){
    
    int A,B;
    cin >> A >> B;
    
    if(A*2>B || A*2==B){
        cout << "E";
    }
    else {
        cout << "H";
    }
    
    return 0;
}