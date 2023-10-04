#include<iostream>

using namespace std;

int main(){
    
    int a,b,c,d;
    
    int x,y,r;
    
    cin >> a>>b>>c>>d;
    cin>>x>>y>>r;
    
    if(a==x)cout << 1;
    else if(b==x)cout << 2;
    else if(c==x)cout << 3;
    else if(d==x)cout << 4;
    else cout << 0;
    
    
    return 0;
}