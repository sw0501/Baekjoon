#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N;			//목표 제곱수
int DP[50001];	//DP[목표값] = 최소 제곱수;	
vector<int>DF;	//1인 것들
int ans=4;		//최소 제곱수

void init();

int search(int C,int D);

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	
	fill_n(DP,50001,5);

	//제곱수 미리 계산하여 DP로 해결
	for(int i=1;i*i<=N;i++){
		DP[i*i] = 1;
	}
	
	//N까지 최소 제곱수를 계산해나간다.
	for(int i=1;i<=N;i++){
		if(DP[i]==5){
			for(int j=1;j*j<=i;j++){
				DP[i] = (DP[i]>(DP[i-j*j]+DP[j*j])?(DP[i-j*j]+DP[j*j]):DP[i]);
			}
		}
	}
	
	//최소 제곱수 출력
	cout << DP[N] << "\n";
}





