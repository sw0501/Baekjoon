#include <bits/stdc++.h>

using namespace std;

void init();
int DFS(int x,int y,int index);

int N,M,K;
char Puzzle[101][101];
int DP[101][101][101];
string Word;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> M >> K;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> Puzzle[i][j];
		}
	}
	
	cin >> Word;
	
	fill(DP[0][0],DP[N][0],-1);
	
	
	int cnt = 0;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			//영단어의 시작문자인 경우 DFS로 경로 탐색
			if(Puzzle[i][j]==Word[0]){
				cnt += DFS(i,j,0);
			}
		}
	}
	
	cout << cnt << "\n";
}

int DFS(int x,int y,int index){
	//이미 경로 탐색이 끝난 경우 값 반환
	if(DP[x][y][index]!=-1){
		return DP[x][y][index];
	}
	//마지막 문자에 도착한 경우 1 반환
	if(Puzzle[x][y]==Word[index]&&index+1 == Word.size()){
		return 1;
	}
	else{
		//탐색했다는 표시
		DP[x][y][index]=0;
		//상하좌우 탐색
		for(int i=0;i<4;i++){
			//이동가능한 거리 탐색
			for(int j=1;j<=K;j++){
				int tx = x+dx[i]*j;
				int ty = y+dy[i]*j;
				//탐색가능한 범위인지 확인
				if((tx>=0&&tx<N)&&(ty>=0&&ty<M)){
					//탐색하려는 문자가 맞는지 확인
					if(Puzzle[tx][ty]==Word[index+1]){
						DP[x][y][index] += DFS(tx,ty,index+1);
					}
				}
			}
		}
		return DP[x][y][index];
	}
	
}

