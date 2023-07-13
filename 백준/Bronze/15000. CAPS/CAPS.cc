#include<iostream>

using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    for(int i=0;i<str.length();i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i] -= 'a'-'A';
        }
    }
    
    cout <<  str << "\n";
    return 0;
}