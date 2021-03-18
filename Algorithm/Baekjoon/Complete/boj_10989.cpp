#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

int counting[10000]={0,}; //counting 배열 0으로 초기화 [1~10000]
int M=0; //입력 받은 값중 최대값

void init(); 	//시작 함수
void Print();	//출력 함수

int main(){
	
	init();
	
	return 0;
}

void init(){
	int N; 		//입력 개수
	int num; 	//입력 받을 값
	cin>>N;		
	for(int i=0;i<N;i++){
		//cin>>num; //사용시 시간초과
		scanf("%d",&num);
		if(num>M)M=num;		//최대값 결정
		counting[num-1]++;	//입력 받은 수 카운팅
	}
	Print();
}

void Print(){
	//숫자 카운트하면서 출력
	for(int i=0;i<M;i++){
		for(int j=counting[i];j>0;j--){
			//cout<<i+1<<"\n";
			printf("%d\n",i+1);
		}
	}
}