#include<iostream>

using namespace std;

int main(){
    
    string str;
    
    cin >> str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='a'){
            str[i] = '4';
        }
        if(str[i]=='e'){
            str[i] = '3';
        }
        if(str[i]=='i'){
            str[i] = '1';
        }
        if(str[i]=='o'){
            str[i] = '0';
        }
        if(str[i]=='s'){
            str[i] = '5';
        }
    }
    
    cout << str << "\n";
    
    
    return 0;
}