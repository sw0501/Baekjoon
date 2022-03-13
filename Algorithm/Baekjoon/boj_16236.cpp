#include <bits/stdc++.h>

using namespace std;

void init();

struct Shark{
	int x;
	int y;
	int size;
	int timw;
	int fish[7]={0,};
};

int N;
int arr[20][20]={0,};

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	Shark s;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> arr[i][j];
			F[arr[i][j]]++;
			if(arr[i][j]==9){
				s.x=i;
				s.y=j;
				s.size=2;
				s.time=0;
			}
			else if(arr[i][j]!=0){
				s.fish[arr[i][j]]++;
			}
		}
	}
	
	queue<Shark>q;
	q.push(S);
	while(!q.empty()){
		Shark T = q.front();
		//도움을 요청해야하는 상황인지 확인
		q.pop();
		
	}
	
}
