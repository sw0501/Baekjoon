#include<iostream>

using namespace std;

int main(){
    
    int N,K;
    cin >> N >> K;
    int coin[100] = {0,};
    for(int i=0;i<N;i++){
        cin >> coin[i];
    }
    
    int DP[10001] = {0,};
    DP[0] = 1;
    
    for(int i=0;i<N;i++){
        //coin 사용할 수 있는 코인의 경우 더하기
        for(int j=coin[i];j<=K;j++){
            DP[j] += DP[j-coin[i]];
        }
    }
    
    cout << DP[K] << "\n";
    
    
    return 0;
}