#include<iostream>

using namespace std;

int main(){
    
    int ans = 0;
    
    int DP[100001][3] = {0,};
    
    DP[1][0] = 1;    //사자가 왼쪽에 있는 경우
    DP[1][1] = 1;    //사자가 오른쪽에 있는 경우  
    DP[1][2] = 1;    //사자가 둘 다 덦는 경우
    
    int N;
    cin >> N;
    
    for(int i=2;i<=N;i++){
        //사자가 왼쪽 칸에 있는 경우
        DP[i][0] = (DP[i-1][1] + DP[i-1][2])%9901;
        //사자가 오른쪽 칸에 있는 경우
        DP[i][1] = (DP[i-1][0] + DP[i-1][2])%9901;
        //사자가 양쪽 칸에 없는 경우
        DP[i][2] = (DP[i-1][0] + DP[i-1][1] + DP[i-1][2])%9901;
    }
    
    cout << (DP[N][0] + DP[N][1] + DP[N][2])%9901 << "\n";
    
    return 0;
}