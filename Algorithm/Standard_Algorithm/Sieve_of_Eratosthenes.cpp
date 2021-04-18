//아리스토텔레스의 체
//소수 구하기

#include<iostream>

using namespace std;

int main(){
	
	
	int N;	//소수를 판별할 마지막 수
	int AR[100001];	//정수 배열
	cin >> N;
	
	//배열 채워주기
	for(int i=0;i<=N;i++){
		AR[i] = i;
	}
	
	for(int i=2;i<=N;i++){
		//체크되지 않은 수라면
		if(AR[i]){
			cout << AR[i] << "\n";
			//자신을 제외한 배수를 0으로 체크
			int temp = 2;
			while(AR[i]*temp<=N){
				AR[AR[i]*temp]=0;
				temp++;
			}
		}
	}
	
	
	
	return 0;
}