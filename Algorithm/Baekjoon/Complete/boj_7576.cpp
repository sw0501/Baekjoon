#include <bits/stdc++.h>

using namespace std;

void init();

int M,N;
queue<pair<pair<int,int>,int>>Q;	//x,y,date
int Box[1000][1000]={0,};	//토마토 상태 표시
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int date = 1;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	return 0;
}

void init(){
	cin >> M >> N;
	
	int T = 0;
	
	for(int y=0;y<N;y++){
		for(int x=0;x<M;x++){
			cin >> Box[y][x];
			//익지않은 토마토 개수 카운트
			if(Box[y][x]==0)T++;
		}
	}
	
	for(int y=0;y<N;y++){
		for(int x=0;x<M;x++){
			if(Box[y][x]==1){
			Q.push(make_pair(make_pair(x,y),1));
			}
		}
	}
	
	while(!Q.empty()){
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int d = Q.front().second;
		Q.pop();		
		for(int i=0;i<4;i++){
			int tx = x+dx[i];
			int ty = y+dy[i];
			if(tx>=0&&ty>=0&&tx<M&&ty<N){
				//탐색위치에 토마토가 있는 경우 Box에 방문 표시 후 익은 날짜를 비교
				if(Box[ty][tx]==0){
					T--;
					Q.push(make_pair(make_pair(tx,ty),d+1));
					Box[ty][tx]=1;
					date = (d+1>date?d+1:date);
				}
			}
		}
	}

	//안익은 토마토가 남아있는 경우
	if(T!=0)cout << "-1" << "\n";
	else cout << date-1 << "\n";
}
