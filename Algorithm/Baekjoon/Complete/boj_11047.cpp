#include<iostream>
#include<algorithm>

using namespace std;

int N;	//동전 종류
int K;	//구하려는 동전의 가치 합
int V[10]={0,};	//동전 가치
int c=0;	//동전의 최소 개수

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin>>V[i];
	}
	//오름차순으로 배열되어있으므로 뒤에서부터 큰 가치의 동전만큼 빼줌
	for(int i=N-1;i>=0;i--){
		c+=K/V[i];	//해당 동전의 최대 개수 더하기
		K%=V[i];		//남은 가치 저장
	}
	cout << c << "\n";
}