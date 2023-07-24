#include<iostream>
#include<cmath>

using namespace std;

int main(){
    
    long long N;
    cin >> N;
    
    if(N%7==2 || N%7==0){
        cout << "CY";
    }
    else cout << "SK";
    
    return 0;
}