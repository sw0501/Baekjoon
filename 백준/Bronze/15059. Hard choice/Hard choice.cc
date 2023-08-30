#include<iostream>

using namespace std;

int main(){
    
    int a,b,c,A,B,C;
    cin >> a >> b >> c;
    cin >> A >> B >> C;
    
    cout << (A-a>0?A-a:0) + (B-b>0?B-b:0) + (C-c>0?C-c:0) << "\n";
    
    return 0;
}