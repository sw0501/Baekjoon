#include<iostream>

using namespace std;

int main(){
    
    int N,K;
    cin >> N >> K;
    int coin[100] = {0,};
    for(int i=0;i<N;i++){
        cin >> coin[i];
    }
    
    int DP[100001] = {0,};   //최소 개수
    DP[0] = 0;
    
    for(int i=0;i<N;i++){
        //coin 사용할 수 있는 코인의 경우 더하기
        for(int j=coin[i];j<=K;j++){
            
            if((j-coin[i] == 0 || DP[j-coin[i]]!=0) && (DP[j] == 0 || DP[j] > DP[j-coin[i]]+1)){
                DP[j] = DP[j-coin[i]]+1;
            }
        }
    }
    /*
    for(int i=0;i<=K;i++){
        cout << i << " : " << DP[i] << "\n";
    }
    */
    if(DP[K] == 0){
        cout << -1 << "\n";
    }
    
    else cout << DP[K] << "\n";
    
    
    return 0;
}