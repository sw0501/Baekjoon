#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;							//길이
long long C=0;					//카운트
long long DP[101][11] = {0,};	//DP[i][j] i:자릿수, j:숫자

void init();

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> N;
	
	//첫째 자리가 0일 수 없음
	DP[1][0] = 0;
	for(int j=1;j<10;j++){
		DP[1][j] = 1;
	}
	
	//N==1인 경우
	if(N==1){
		C=9;
	}
	
	else{
		for(int i=2;i<=N;i++){
			for(int j=0;j<10;j++){
				//자릿수가 0인 경우 무조건 1
				if(j==0){
					DP[i][j] = DP[i-1][j+1]%1000000000;
				}
				//자릿수가 9인 경우 무조건 8
				else if(j==9){
					DP[i][j] = DP[i-1][j-1]%1000000000;
				}
				//자릿수가 1~8인 경우 (j-1) + (j+1)
				else{
					DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1])%1000000000;
				}
				
				//종료 시점일 경우
				if(i==N){
					C += DP[i][j]%1000000000;
				}
			}
		}
	}
	
	//stair(1);
	
	//1000000000으로 나눈 나머지 출력
	cout << C%1000000000 << "\n";
}
