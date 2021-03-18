#include<iostream>
#include<algorithm>

using namespace std;

int N; //최대 수
int M; //수열 포함되는 숫자 개수 
int *arr; //수열 저장

void init();
void array(int m);

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> N >> M;
	arr = new int[M];
	array(1);
	delete []arr;
}

void array(int m){
	//수열에 숫자 저장
	for(int i=1;i<=N;i++){
		arr[m-1]=i;
		int temp = 1; //조건 확인 변수
		for(int j=0;j<m-1;j++){
			if(arr[m-1]<arr[j])temp=0;
		}
		if(temp){
			if(m==M){
				for(int k=0;k<M;k++){
					cout << arr[k] << " ";
				}
				cout << "\n";
			}
			//조건을 만족하지 않는다면
			else array(m+1);
		}
		
	}
}

