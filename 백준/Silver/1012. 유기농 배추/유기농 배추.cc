#include <bits/stdc++.h>

using namespace std;

void init();
void DFS(int x,int y);

int T;
int N,M,C;
int field[2500][2500]={0,};

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> T;
	for(int t=0;t<T;t++){
		
		fill(field[0],field[2500],0);
		
		int answer = 0;
		cin >> N >> M >> C;
		
		
		for(int i=0;i<C;i++){
			int x,y;
			cin >> y >> x;
			field[y][x] = 1;
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				//첫 방문하는 경우
				if(field[i][j]==1){
					answer++;
					DFS(j,i);
				}
			}
		}
		cout << answer << "\n";
	}
}

void DFS(int x,int y){
	field[y][x] = 0;
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};
	for(int i=0;i<4;i++){
		int tx = x+dx[i];
		int ty = y+dy[i];
		if(tx>=0&&tx<M&&ty>=0&&ty<N){
			if(field[ty][tx]==1){
				DFS(tx,ty);
			}
		}
	}
}
