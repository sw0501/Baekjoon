#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    int DP[101][101] = {0,};
    
    for(int i=0;i<puddles.size();i++){
        DP[puddles[i][1]-1][puddles[i][0]-1] = -1;
    }
    
    DP[0][0] = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(DP[i][j] == -1)continue;
            
            int top = (i==0 || DP[i-1][j] == -1 ? 0 : DP[i-1][j]);
            int left = (j==0 || DP[i][j-1] == -1 ? 0 : DP[i][j-1]);
            
            DP[i][j] += (top + left) % 1000000007;
        }
    }
    
    answer = DP[n-1][m-1];
    
    return answer;
}