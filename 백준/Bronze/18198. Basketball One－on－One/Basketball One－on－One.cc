#include<iostream>

using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    int a=0,b=0;
    int flag = 0;
    for(int i=0;i<str.length();i+=2){
        if(str[i]=='A'){
            a+=(int)(str[i+1]-'0');
        }
        else{
            b+=(int)(str[i+1]-'0');
        }
        if(a==10&&b==10)flag = 1;
        
        if(flag){
            if(a-b>1){
                break;
            }
            else if(b-a>1){
                break;
            }
        }
        else{
            if(a==11){
                break;
            }
            else if(b==11){
                break;
            }
        }
    }
    if(a>b){
        cout << 'A' << "\n";
    }
    else {
        cout << 'B' << "\n";
    }
    
    return 0;
}