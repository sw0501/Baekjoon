#include<iostream>
#include<algorithm>

using namespace std;

int N;
int AR[10001];
int C=0;
int S=0;

void init();

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> AR[i];
		if(AR[i]>1)C++;
	}
	
	//정렬
	sort(AR,AR+N);
	
	int temp=C%2;	//첫 양수 거르기
	
	if(N==1)cout << AR[0] << " ";
	
	else{
		for(int i=0;i<N;i++){
		
			//음수 or 0인 경우
			if(AR[i]<=0){
				if(AR[i+1]<=0){
					S+=AR[i]*AR[i+1];
					i++;
				}
				else S+=AR[i];
			}

			//양수인 경우
			if(AR[i]>0){
				//1인 경우
				if(AR[i]==1){
					S+=AR[i];
				}
				//1보다 큰 양수가 홀수 인 경우
				else if(temp){
					temp=0;
					S+=AR[i];
				}
				//짝수인 경우
				else {
					S+=AR[i]*AR[i+1];
					i++;
				}
			}
		}

		cout << S << "\n";

	}
	
	
	//정렬해준 큰 수 부터 묶어준다
	//처리해야 할 것들 
	//0은 음수랑만 묶어야한다.
	//음수가 짝수 개인 경우 음수만 묶어야한다. 0도 음수로 카운팅해야한다.0을 곱하면 음수가 없어지므로
	//1은 무조건 더해야한다 곱하면 1이 사라져버림
}
