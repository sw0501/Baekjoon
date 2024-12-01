#include<iostream>

using namespace std;

int main(){
    
    string str;
    
    cin >> str;
    
    int a=0,b=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='B')a++;
        else b++;
    }
    
    cout << (int)(a/2) + (int)(b/2) << "\n";
    
    return 0;
}