#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int ans = 0;
    int x,y;
    for(int i=0;i<N;i++){
        cin >> x >> y;
        ans += y%x;
    }
    cout << ans << "\n";
}