#include<iostream>

using namespace std;

int main(){
    
    string str;
    string ans = "";
    cin >> str;
    
    ans += str[0];
    
    for(int i=1;i<str.length();i++){
        if(str[i]=='-'){
            ans += str[i+1];
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}