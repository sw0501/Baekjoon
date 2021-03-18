#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;			
int T[1000][3];	//각 줄의 탭 개수, 올바른 탭 개수, 수정해야할 탭 개수
int c=0;	//편집 회수

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> T[i][0];
	}
	for(int i=0;i<N;i++){
		cin >> T[i][1];
		T[i][2] = T[i][1] - T[i][0];
	}
	int i=0;
	while(i<N){
		//탭을 추가해야하는 경우
		if(T[i][2]>0){
			int id=i;
			int temp=T[i][2];
			//함께 추가할 줄 선택 및 가장 적은 작업 개수 저장 중간 줄이 정확해지면 한번에 처리 X
			for(int j=i+1;j<N;j++){
				if(T[j][2]>0){
					id=j;
					temp = min(temp,T[j][2]);
				}
				else break;
			}
			//공통 작업 진행
			for(int j=i;j<id+1;j++){
				T[j][2]-=temp;
			}
			c+=temp;
		}
		//탭을 제거해야하는 경우
		else if(T[i][2]<0){
			int id=i;
			int temp=-T[i][2];
			//함께 제거할 줄 선택 및 가장 적은 작업 개수 저장 중간 줄이 정확해지면 한번에 처리 X
			for(int j=i+1;j<N;j++){
				if(T[j][2]<0){
					id=j;
					temp = min(temp,-T[j][2]);
				}
				else break;
			}
			//공통 작업 진행
			for(int j=i;j<id+1;j++){
				T[j][2]+=temp;
			}
			c+=temp;
		}
		//탭의 개수가 이미 정확한 경우
		else i++;
	}
	cout << c;
}
