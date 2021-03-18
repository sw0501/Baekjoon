#include<iostream>

using namespace std;

int N;
int Arr[1001][2];	//DP  [0] = 발판 [1] = 횟수


void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;

	//발판 입력 및 횟수 초기화
	for(int i=0;i<N;i++){
		cin >> Arr[i][0];
		Arr[i][1] = 1001;
	}
	
	//처음 발판은 무조건 밟기 때문에 1저장	
	Arr[0][1]=0;
	
	//배열의 범위를 넘어설 수 있음
	for(int i=0;i<N;i++){
		//갈 수 있는 발판들에 최소 횟수 저장
		for(int j=1;j<=Arr[i][0];j++){
			Arr[i+j][1]=min(Arr[i+j][1],Arr[i][1]+1);
		}
	}
	/*
	for(int i=0;i<N;i++){
		cout << Arr[i][0] << " " << Arr[i][1] << "\n";
	}
	*/
	//탈출할 수 없다면 -1출력 아니라면 횟수 출력
	if(Arr[N-1][1]==1001)cout << "-1" << "\n";
	else cout << Arr[N-1][1] << "\n";
}
