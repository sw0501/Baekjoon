#include<iostream>

using namespace std;

int main(){
    
    int h,m;
    cin >> h >> m;
    
    int ans = (h-9)*60+(m);
    
    cout << ans << "\n";
    
    return 0;
}