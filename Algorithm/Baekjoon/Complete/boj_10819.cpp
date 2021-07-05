#include<iostream>
#include<algorithm>

using namespace std;

int N;		
int arr[9];			//입력 숫자 배열
int Arr[9];			//순서가 바뀌는 숫자 배열
int flag[9]={0,};	//숫자 사용여부 탐색
int M=0;			//최대값 저장

void init();

//숫자 저장
void search(int D);	//D:깊이

//계산
int Cal();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	
	//모든 순서의 경우의 수를 따져서 계산
	search(0);
	
	cout << M << "\n";
}

void search(int D){
	for(int i=0;i<N;i++){
		//이미 사용한 숫자라면 다음 숫자로 넘어감
		if(flag[i])continue;
		
		//사용하지 않은 수를 발견한 경우라면 숫자를 선택
		flag[i]=1;
		Arr[D]=arr[i];
		
		//깊이가 최대라면 저장한 결과 비교후 다음 숫자로 넘어감
		if(D==N-1){
			M = max(M,Cal());
		}
		
		//깊이가 최대가 아니라면 다음 구간 탐색
		else{
			search(D+1);
		}
		
		//사용한 숫자 반환
		flag[i]=0;
	}
}

int Cal(){
	int temp=0;
	for(int i=1;i<N;i++){
		temp += (Arr[i-1]-Arr[i]>0?Arr[i-1]-Arr[i]:Arr[i]-Arr[i-1]);
	}
	return temp;
}



