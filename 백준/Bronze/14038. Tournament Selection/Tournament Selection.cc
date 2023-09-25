#include<iostream>

using namespace std;

int main(){
    
    char s;
    int ans = 0;
    for(int i=0;i<6;i++){
        cin >> s;
        if(s=='W')ans++;
    }
    if(ans>=5)cout << 1;
    else if(ans>=3)cout<<2;
    else if(ans>=1)cout<<3;
    else cout<<-1;
    
    
}