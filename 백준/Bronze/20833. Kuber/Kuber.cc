#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int ans = 0;
    for(int i=1;i<=N;i++){
        ans += i*i*i;
    }
    cout << ans << "\n";
    return 0;
}