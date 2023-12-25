#include <string>
#include <vector>
#include <iostream>

using namespace std;

int DP[100001] = {0,};

int solution(int n, vector<int> money) {
    int answer = 0;

    //아무것도 거슬러주지 않는 경우 1
    DP[0]=1;
    
    for(int i=0;i<money.size();i++){
        for(int j=money[i];j<=n;j++){
            DP[j] += DP[j-money[i]];
        }
    }
    
    return DP[n];
}