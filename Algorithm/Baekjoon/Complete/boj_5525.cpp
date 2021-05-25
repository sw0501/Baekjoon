#include<iostream>
#include<algorithm>

using namespace std;

int N,S;
char CK[2]={'I','O'};
string str;

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	return 0;
}

void init(){
	cin >> N >> S;
	cin >> str;
	
	int ans = 0;	//P(N)의 개수
	int C = 0;		//연속된 IOI 개수
	int i = 0;		//현재 배열의 위치
	int idx = -1;	//세고있는 i의 위치
		
	for(i=0;i<S;i++){
		
		//기록을 하지 않는 상태에서 I를 발견했다면
		if(idx==-1&&str[i]=='I'){
			idx = i;
		}
		
		//idx가 저장된 상태에서
		if(idx!=-1&&idx!=i){
			//str[i]가 연속된 형태라면
			if(str[i]==CK[(i-idx)%2]){
				//cout << (i-idx)%2 << "\n";
				//I라면 연속된 카운트 저장
				if((i-idx)%2==0)C++;
			}
			//같지 않다면 C에서 만들수 있는 P(N) 개수 저장후 idx와 C 초기화
			else{
				ans += (C-N+1>0?C-N+1:0);
				C = 0;
				//I라면 다시 카운트 시작
				if(str[i]=='I'){
					idx = i;
				}
				else {
					idx = -1;
				}
			}
		}
	}
	
	//연속된상태에서 종료될 경우 남은 C에서 P(N)개수 저장
	ans += (C-N+1>0?C-N+1:0);
	
	cout << ans << "\n";
	
}
