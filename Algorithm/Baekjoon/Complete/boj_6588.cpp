#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int num;			//골드바흐의 추측 구할 수
int AR[1000001];	//정수 배열
vector<int>decimal;	//소수 벡터

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	
	for(int i=0;i<=1000000;i++){
		AR[i] = i;
	}
	
	//소수 테이블 구해놓기
	for(int i=2;i<=1000000;i++){
		//체크되지 않은 수라면
		if(AR[i]){
			decimal.push_back(i);
			//자신을 제외한 배수를 0으로 체크
			int temp = 2;
			while(AR[i]*temp<=1000000){
				AR[AR[i]*temp]=0;
				temp++;
			}
		}
	}
	
	
	while(1){
		cin >> num;
		if(num==0)break;
		int flag = 1;	//출력여부 확인
		
		for(int i=0;i<decimal.size();i++){
			
			if(decimal[i]>=num)break;
			
			if(AR[num-decimal[i]]!=0){
				cout << num << " = " << decimal[i] << " + " << AR[num-decimal[i]] << "\n";
				flag = 0;
				break;
			}
		}
		
		if(flag)cout << "Goldbach's conjecture is wrong." << "\n";
	}
	
	
}



