#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

int N;
int answer = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int Grid[2001][2001]={0,};
int Visit[2001][2001]={0,};
int Box[1001][4]={0,};
queue<pair<int,int>> q;

void init();
void BFS();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> Box[i][0] >> Box[i][1] >> Box[i][2] >> Box[i][3];
		
		if(Box[i][0]>Box[i][2]){
			int temp = Box[i][0];
			Box[i][0] = Box[i][2];
			Box[i][2] = temp;
		}
		if(Box[i][1]>Box[i][3]){
			int temp = Box[i][1];
			Box[i][1] = Box[i][3];
			Box[i][3] = temp;
		}
		
		for(int j=0;j<4;j++){
			Box[i][j] = 2*(Box[i][j]+500);
		}
		
		
		//Grid에 그린다 
		for(int j=Box[i][0];j<=Box[i][2];j++){
			Grid[j][Box[i][1]] = 1;
			Grid[j][Box[i][3]] = 1;
		}
		for(int j=Box[i][1];j<=Box[i][3];j++){
			Grid[Box[i][0]][j] = 1;
			Grid[Box[i][2]][j] = 1;
		}
		
	}
	
	
	
	for(int i=0;i<N;i++){
		if(Visit[Box[i][0]][Box[i][1]]==0){
			q.push(make_pair(Box[i][0],Box[i][1]));
			Visit[Box[i][0]][Box[i][1]] = 1;
			BFS();
			answer++;
		}
	}
	
	//0,0에 선이 지나는지 확인
	if(Grid[1000][1000]==1)answer--;

	cout << answer << "\n";
	
}

void BFS(){
	
	while(!q.empty()){
		
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		for(int i=0;i<4;i++){
			//배열의 범위 밖을 탐색하기때문에 오류 발생
			if(x+dx[i]>=0 && x+dx[i]<=2000 && y+dy[i] >= 0 && y+dy[i] <= 2000){
				if(Grid[x+dx[i]][y+dy[i]]==1&&Visit[x+dx[i]][y+dy[i]]==0){
					Visit[x+dx[i]][y+dy[i]]=1;
					q.push(make_pair(x+dx[i],y+dy[i]));
				}
			}
		}
	}
	
}


