#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

string s1;
string s2;
int dp[1001][1001]={0,};

void init();
void Com();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	int idx;
	int c;
	int M=0;
	
	cin >> s1 >> s2;
	
	//s1과 s2를 비교하면서 해당 문자가 들어있는지 확인 후 DP에 저장
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			//s1과 s2가 같다면 대각선 아래 DP값에 1 더하여 저장
			if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
			//같지 않다면 대각선 아래 DP값과 바로 전 DP값 비교하여 큰 것을 넣어준다
			//바로 전 DP : 공통이 아니어서 0이 나올 수도 있기 때문에
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			//MAX 비교
			M=max(M,dp[i][j]);
		}
	}
	
	cout << M << "\n";
}
