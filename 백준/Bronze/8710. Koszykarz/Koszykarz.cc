#include<iostream>

using namespace std;

int main(){
    
    int a,b,c;
    cin >> a >> b >> c;
    
    int cm = (b - a);
    int ans = 0;
    while(cm>0){
        cm-=c;
        ans++;
    }
    
    cout << ans << "\n";
    return 0;
}