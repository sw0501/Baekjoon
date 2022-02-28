#include <bits/stdc++.h>

using namespace std;

void init();
void BFS();

int N,M;
int Maze[100][100]={0,};
int CK[100][100]={0,};
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
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			char ch;
			cin >> ch;
			if(ch=='1')Maze[i][j]=1;
		}
	}
	BFS();
	cout << Maze[N-1][M-1] << "\n";
}

void BFS(){
	queue<pair<pair<int,int>,int>>Q;
	Q.push(make_pair(make_pair(0,0),1));
	
	while(!Q.empty()){
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int C = Q.front().second;
		Q.pop();
		
		Maze[x][y] = C;
		CK[x][y] = 1;
		for(int i=0;i<4;i++){
			int tx = x+dx[i];
			int ty = y+dy[i];
			if(tx>=0&&ty>=0&&tx<N&&ty<M){
				if(Maze[tx][ty]!=0){
					//방문하지 않은 경우
					if(CK[tx][ty]==0){
						CK[tx][ty]=1;
						Maze[tx][ty] = C+1;
						//도착지인 경우 큐에 삽입 X
						if(!(tx==N-1&&ty==M-1)){
							Q.push(make_pair(make_pair(tx,ty),C+1));
						}
					}
					//방문한 경우 횟수를 비교하여 적은 경우에만 탐색
					else{
						if(Maze[tx][ty]>C+1){
							Maze[tx][ty] = C+1;
							//도착지인 경우 큐에 삽입 X
							if(!(tx==N-1&&ty==M-1)){
								Q.push(make_pair(make_pair(tx,ty),C+1));
							}
						}
					}
				}
			}
		}
	}
}