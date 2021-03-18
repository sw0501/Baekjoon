#include<iostream>
#include<algorithm>

using namespace std;

int N;				//입력 개수 (홀수)
double average=0; 	//산술평균 (반올림을 위해서 double로 저장)
int midean;			//중앙값
int mode;			//최빈값
int range;			//범위
int *arr; 			//배열
int *counting;		//카운팅

void init();

int main(){
	
	init();
	
	return 0;
}

void init(){
	//카운팅 배열 0으로 초기화
	counting = new int[8001];
	for(int i=0;i<8001;i++){
		counting[i]=0;
	}
	//입력
	cin>>N;
	arr = new int[N];
	for(int i=0;i<N;i++){
		cin>>arr[i];
		counting[arr[i]+4000]++;
		average+=(double)arr[i];
	}
	
	//arr 정렬
	sort(arr,arr+N);
	
	//산술평균
	if(average<0)
	average = average/(double)N-0.5;
	else
	average = average/(double)N+0.5;
	
	//최빈값
	int m=0; //최빈값 비교
	int temp=1; //최빈값 같은 경우에 사용
	//최빈값이 더 큰 경우 m=i, 최빈값이 같은 경우에 m=i && temp를 이용해 다음 최빈값이 같은 경우가 발생안하도록 막음
	//int i = 0일 경우 -4000에 자기자신이 위치한 경우 바로 temp가 0이 돼서 비교 불가능
	for(int i=1;i<8001;i++){
		if(counting[i]>counting[m]){
			m=i;
			temp=1;
		}
		else if(counting[i]==counting[m]&&temp){
			m=i;
			temp=0;
		}
	}
	mode = m-4000;

	//중앙값
	midean = arr[N/2];
	
	//범위
	range=arr[N-1]-arr[0];
	
	//출력
	cout << (int)average << "\n" << midean << "\n" << mode << "\n" << range << "\n";
	
	/*
	for(int i=0;i<N;i++){
		cout << arr[i] << "\n";
	}
	*/
	delete[]counting;
	delete[]arr;
}


