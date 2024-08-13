#include<iostream>

using namespace std;

int main(){
    
    string str;
    
    cin >> str;
    
    int cnt = 0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='e'){
            cnt++;
        }
        else if(str[i]=='y'){
            for(int j=0;j<cnt;j++){
                cout<<'e';
            }
        }
        cout << str[i];
    }
    
    return 0;
}