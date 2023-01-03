#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string N;
int DP[5002][2];

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	
	getline(cin,N);
	
	int L = N.length();
	
	//수 분해하여 DP에 저장
	for(int i=1;i<=L;i++){
		DP[i][0] = (int)(N[i-1]-'0');
		DP[i][1] = 0;
	}
	
	//초기값은 1 맨 처음 숫자는 중복해석 불가능
	DP[0][0]=0;
	DP[0][1]=1;
	
	int temp = 1;
	
	int answer=0;
	
	//암호를 해석할 수 없는 경우
	//x < 10 && x = 0일 때
	
	//수를 분석하여 DP[i][1]에 저장
	for(int i=1;i<=L;i++){
		
		//해석가능한 다른 수
		int num=DP[i-1][0]*10+DP[i][0];
		
		//DP[i][0] == 0인 경우
		if(DP[i][0]==0){
			//해석 가능한 경우 00 or 10 or 20
			if(DP[i-1][0]==1||DP[i-1][0]==2){
				//i-1에서 중복해석한 경우
				if(DP[i-2][1]!=DP[i-1][1]){
					DP[i-1][1] = DP[i-2][1];
				}
				DP[i][1] = DP[i-1][1]%1000000;
			}
			//해석이 불가능한 경우
			else {
				temp = 0;
				break;
			}
			
		}
		
		//중복 해석이 가능한 경우
		else if(num>10&&num<=26){
			DP[i][1] = (DP[i-1][1] + DP[i-2][1])%1000000;
		}
		
		else{
			DP[i][1] = DP[i-1][1]%1000000;
		}
		
		if(i==L)answer = DP[L][1];
	}
	
	
	if(temp)cout << answer << "\n";
	else cout << "0" << "\n";
}


