#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    
    int a,b,c;
    cin >> a >> b >> c;
    int A,B,C;
    
    A = min(a,min(b,c));
    C = max(a,max(b,c));
    
    if(a!=A && a!=C){
        B = a;
    }
    else if(b!=A && b!=C){
        B = b;
    }
    else if(c!=A && c!=C){
        B = c;
    }
    
    
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='A')cout << A << " ";
        else if(str[i]=='B')cout << B << " ";
        else if(str[i]=='C')cout << C << " ";
    }
    
    
    
    return 0;
}