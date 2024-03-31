#include<iostream>

using namespace std;

int main(){
    
    int a,b,c,d,e;
    
    cin >> a>> b>> c>> d>> e;
    
    int N = e*4;
    int avg = a+b+c+d;
    
    cout << (N-avg>0?N-avg:0) << "\n";
    
    return 0;
}