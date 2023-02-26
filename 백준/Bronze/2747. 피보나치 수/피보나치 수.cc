#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    int DP[47] = {0,};
    DP[0] = 0;
    DP[1] = 1;
    for(int i=2;i<=N;i++){
        DP[i] = DP[i-1] + DP[i-2];
    }
    cout << DP[N] << "\n";
    
    return 0;
}