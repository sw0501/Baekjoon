#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int N;
int cnt[100001]={0,};
int DP[100001]={0,};	//제곱수의 최소항

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	
	cin >> N;
	
	int C=0;
	DP[1]=1; DP[2]=2; DP[3]=3;
	
	//DP에 제곱수 항의 개수를 저장하며 반복한다.
	for(int i=4;i<=N;i++){
		C=0;	//제곱수의 항 카운트
		
		//DP[i] = DP[i-j*j]+1 로 표현할 수 있으므로 해당 항의 개수 저장하고 정렬하여 최소 개수 구함
		for(int j=sqrt(i);j>=1;j--){
			if(j*j<=i)cnt[C++] = DP[i-j*j]+1;
		}
		//최소항으로 정렬한 후 가장 작은 수를 DP에 저장
		sort(cnt,cnt+C);
		DP[i]=cnt[0];
		
		//cnt 배열 초기화
		while(C--){
			cnt[C]=0;
		}
	}
	cout << DP[N] << "\n";
}


