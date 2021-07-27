#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    
    int DP[1001][1001]={0,};
    
    for(int i=1;i<=n;i++){
		string temp;
		cin >> temp;
        for(int j=1;j<=m;j++){
			DP[i][j] = (int)(temp[j-1]-'0');
        }
    }
    
    int result = 0;
    
	//선택한 부분 주변의 연속된 1의 개수를 탐색하여 가장 작은 것을 DP로 저장한다,
	//탐색이 진행될수록 DP[i][j]에 연속된 1의 개수가 쌓이고 가장 큰 것을 고르는데 이 값이 정사각형의 변의 길이이다.
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i!=0&&j!=0&&DP[i][j]!=0){
                DP[i][j] = min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1]))+1;
            }
            result = max(result,DP[i][j]);
        }
    }
    
    cout << result*result << "\n";
}