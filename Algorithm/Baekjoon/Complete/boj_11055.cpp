//배운 거 써먹어보는 것도 좋지만 조건에 명시안되어있으면 간단하게 푸는 것도 방법중 하나다.
#include<iostream>
#include<algorithm>

using namespace std;

int N;
int AR[1001]={0,};
int DP[1001]={0,};

void init();

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> AR[i];
		DP[i] = AR[i];
	}
	
	//DP에 증가하는 부분 수열의 가장 큰 합을 저장하고 계속해서 비교해나간다
	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){
			//증가하는 부분수열이라면 기존 DP와 해당 수열의 DP의 합을 비교하여 더 큰 것 저장
			if(AR[j]<AR[i])DP[i] = max(DP[i],DP[j]+AR[i]);
		}
	}
	
	int M=0;
	for(int i=0;i<N;i++){
		if(DP[i]>M)M=DP[i];
	}
	
	
	cout << M << "\n";
}