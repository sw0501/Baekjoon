#include<iostream>
#include<algorithm>
using namespace std;

int N; //사람 수
int P[1000]; //인출 소요 시간
int per_time=0; //인당 걸리는 시간
int min_time=0; //누적 시간

int main(){
	
	//입력
	cin >> N;
	for(int i=0;i<N;i++){
		cin>>P[i];
	}
	
	//최소 시간이 걸리려면 가장 소요 시간이 작은 사람부터 인출하면 된다.
	sort(P,P+N); //P[0]부터 P[N-1]까지 정렬
	//per_time에 인당 걸리는 시간을 저장, min_time에 누적 시간을 저장
	for(int i=0;i<N;i++){
		per_time+=P[i];
		min_time+=per_time;
	}
	cout << min_time; //출력
	
	return 0;
}