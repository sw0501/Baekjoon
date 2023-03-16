#include<iostream>

using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    int ans = 10;
    
    for(int i=1;i<str.length();i++){
        if(str[i-1]!=str[i])ans+=10;
        else ans+=5;
    }
    
    cout << ans << "\n";
    
    return 0;
}