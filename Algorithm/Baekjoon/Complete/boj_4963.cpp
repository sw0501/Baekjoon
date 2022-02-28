#include <bits/stdc++.h>

using namespace std;

void init();
void DFS(int x,int y);

int MAP[51][51];
int w;
int h;
int I = 0;
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
	
	cin >> w >> h;
	while(!(w==0&&h==0)){
		I=0;
		fill(MAP[0],MAP[0]+51,0);
		
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin >> MAP[i][j];
			}
		}
		
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				//탐색하지 않은 땅이라면 탐색 진행
				if(MAP[i][j]!=0){
					DFS(j,i);
					I++;
				}
			}
		}
		
		cout << I << "\n";
		
		cin >> w >> h;
	}
}

void DFS(int x,int y){
	//방문 체크
	MAP[y][x] = 0;
	
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			int tx = x+j;
			int ty = y+i;
			//탐색 가능한 범위인 경우
			if(tx>=0&&ty>=0&&tx<w&&ty<h){
				if(MAP[ty][tx]!=0)DFS(tx,ty);
			}
		}
	}
}
