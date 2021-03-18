#include<iostream>
#include<algorithm>

using namespace std;

int N;				//카드 개수
int C=0;			//현재 구매한 개수
int P[1001];		//가격
int DP[1001]={0,};	//DP

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> P[i];
	}
	
	//DP를 통해 카드를 i개 살때 최대값을 정해두고 DP를 순회하면서 체크하면 됨
	DP[1] = P[1];
	DP[2] = max(2*DP[1],P[2]);
	
	//i가 되는 경우의 DP를 비교해가면서 최대값 저장
	for(int i=3;i<=N;i++){
		int temp = P[i];
		for(int j = 1;j<=i/2;j++){
			temp = max(temp,DP[j]+DP[i-j]);
		}
		DP[i] = temp;
	}
	cout << DP[N] << " ";
}
