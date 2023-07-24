#include<iostream>
#include<cmath>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int DP[1001] = {0,};
    
    DP[1] = 1;
    DP[2] = 0;
    DP[3] = 1;
    DP[4] = 1;
    DP[5] = 1;
    
    for(int i=6;i<=N;i++){
        DP[i] = (DP[i-1]+DP[i-3]+DP[i-4]!=3?1:0);
    }
    
    //cout << DP[N] << "\n";
    
    if(DP[N]%2==1){
        cout << "SK";
    }
    else cout << "CY";
    
    return 0;
}