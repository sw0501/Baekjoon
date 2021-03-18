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
			if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			M=max(M,dp[i][j]);
		}
	}
	
	/*
	for(int i=0;i<=s1.length();i++){
		for(int j=0;j<=s2.length();j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	
	cout << M << "\n";
}
