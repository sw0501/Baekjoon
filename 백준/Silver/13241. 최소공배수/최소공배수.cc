#include<iostream>

using namespace std;

int main(){
    
    long long int A, B;
    
    cin >> A >> B;
    
    long long int a = A;
    long long int b = B;
    
    while(1){
        int c = a%b;
        if(c==0)break;
        a = b;
        b = c;
    }
    
    cout << A * B / b << "\n";
    
    return 0;
}