#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dp[21][21][21]={0,};

void init();
int W(int a,int b,int c);
int w(int a,int b,int c);

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	while(1){
		int a,b,c;
		cin >> a >> b >> c;
		if(a==-1&&b==-1&&c==-1)break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c) << "\n";
	}
}


int w(int a,int b,int c){
	//cout << a << b << c << "\n";
	if(a<=0||b<=0||c<=0)return 1;
	if(a>20||b>20||c>20)return w(20,20,20);
	//DP에 저장안되어있다면 계산후 DP에 저장
	//이런 식으로 저장하면 아래 DP(DP[0][0][0])부터 쌓이기때문에 반복되는 계산을 줄일 수 있음
	if(dp[a][b][c]!=0)return dp[a][b][c];
	//계산하는 과정을 거치기 전 DP에 저장되어있는지 확인
	if(a<b&&b<c){
		dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
		return dp[a][b][c];
	}
	dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
	return dp[a][b][c];
}

