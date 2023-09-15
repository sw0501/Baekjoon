#include<iostream>

using namespace std;

int main(){
    
    int N;
    int a,b,c;
    cin >> N;
    cin >> a >> b >> c;
    
    cout << (a>N?N:a) + (b>N?N:b) + (c>N?N:c);
    
    return 0;
}