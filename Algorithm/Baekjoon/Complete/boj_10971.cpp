#include<iostream>
#include<algorithm>

using namespace std;

int N;			//도시의 개수
int W[10][10];	//도시간 이동 비용
int CK[10]={0,};//방문한 도시 체크
int answer=4000000;	//도시 방문에 필요한 가장 적은 비용
int F=0;		//첫번째 방문한 도시 저장
void init();
void DFS(int D,int Price, int C);

int main(){
	
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> W[i][j];
		}
	}
	for(int i=0;i<N;i++){
		F=i;
		CK[i]=1;
		DFS(i,0,0);
		CK[i]=0;
	}
	
	cout << answer << "\n";
}


void DFS(int D,int Price,int C){
	if(C==N-1){
		if(W[D][F]!=0)answer = (answer<Price+W[D][F]?answer:Price+W[D][F]);
		return ;
	}
	for(int i=0;i<N;i++){
		if(CK[i]==1)continue;
		if(W[D][i]!=0){
			CK[i]=1;
			DFS(i,Price+W[D][i],C+1);
			CK[i]=0;
		}
	}
}
