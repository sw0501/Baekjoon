#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
long long D[100000];		//첫번째 도시에서 출발하기 때문에 1번도시는 거리 0
long long price[100001];	//각 도시의 기름 가격
long long m=0;	//최소 비용
long long M=0;	//기름값
int num=0;	//도시 위치
	
void init();

int main(){
	
	init();
	
	
	return 0;
}

//주유소를 들러야하는 도시는 기름 값이 이전 도시들보다 싼 곳일 것이다.
//자신보다 가격이 싼 도시까지 가는데 필요한 기름만 사면 그리읻 완성
void init(){
	cin >> N;
	
	for(int i=0;i<N-1;i++){
		cin >> D[i];
	}
	
	for(int i=0;i<N;i++){
		cin >> price[i];
	}
	
	M=price[0];
	for(int i=0;i<N;i++){
		//기름 가격이 싸다면
		if(M>price[i]||i==N-1){
			for(int j=num;j<i;j++){
				m+=D[j]*price[num];
			}
			M=price[i];
			num=i;
		}
	}
	cout << m << "\n";
}
