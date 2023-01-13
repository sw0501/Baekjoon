#include<iostream>

using namespace std;

int main(){
    
    int A,B;
    
    cin >> A >> B;
    
    A = A/2;
    B = B/2;
    
    cout << (A>B?B:A) << "\n";
    
    return 0;
}