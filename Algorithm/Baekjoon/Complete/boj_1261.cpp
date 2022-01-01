#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>	//greater,less
#include<utility>		//pair

using namespace std;

void init();
void BFS();

class Mem{
	
	public:
	int x;
	int y;
	int Wall;
	
	Mem(int x,int y,int Wall){
		this->x = x;
		this->y = y;
		this->Wall = Wall;
	}
	
};

bool operator < (Mem m1,Mem m2){
	return m1.Wall < m2.Wall;
} 

priority_queue<Mem>pq;	//BFS용 큐 <<x,y>,뚫은 벽 개수>

int N,M;	//가로, 세로
string maze[101];		//미로
int Visit[101][101];	//뚫은 벽의 개수
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
	
		cin >> M >> N;
	
		fill(Visit[0],Visit[101],-1);

		for(int i=1;i<=N;i++){
			cin >> maze[i];
		}

		pq.push(Mem(1,1,0));
		Visit[1][1] = 0;

		BFS();
	
}


//우선순위 큐를 사용하여 벽을 적게 부순것 부터 사용해야한다

void BFS(){
	//길이 있다면 진행 없다면 벽을 뚫어서 간다?
	//Visit에 그동안 뚫은 벽의 개수를 비교하여 더 적게 뚫은 경우에만 큐에 삽입
	while(!pq.empty()){
		int x = pq.top().x;
		int y = pq.top().y;
		int Wall = pq.top().Wall;
		
		//cout << x << " " << y << " " << Wall << "\n";
		pq.pop();
		
		//if(Visit[N][M]>-1&&Wall>Visit[N][M])continue;
		
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if((nx>=1&&nx<=M)&&(ny>=1&&ny<=N)){
				//한번도 방문하지 않은 칸 이라면
				if(Visit[ny][nx]==-1){
					//열린 방인 경우
					if(maze[ny][nx-1]=='0'){
						Visit[ny][nx] = Wall;
						pq.push(Mem(nx,ny,Wall));
					}
					else{
						Visit[ny][nx] = Wall+1;
						pq.push(Mem(nx,ny,Wall+1));
					}
				}
				//이미 방문한 칸인 경우 벽을 뚫은 횟수가 더 적은 경우에만 재탐색
				else{
					//열린 방인 경우
					if(maze[ny][nx-1]=='0'&&Wall<Visit[ny][nx]){
						Visit[ny][nx] = Wall;
						pq.push(Mem(nx,ny,Wall));
					}
					else if(Wall+1<Visit[ny][nx]){
						Visit[ny][nx] = Wall+1;
						pq.push(Mem(nx,ny,Wall+1));
					}
				}
			}
		}
	}
	
	//도착지에 도달할때까지 뚫은 벽의 개수를 출력
	cout << Visit[N][M] << "\n";
}



