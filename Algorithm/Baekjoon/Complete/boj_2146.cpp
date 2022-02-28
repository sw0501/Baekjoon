#include <bits/stdc++.h>

using namespace std;

void init();
void BFS();

int N;
int Map[100][100] = {0,};
int CK[100][100] = {0,};
int result = 100000;
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
	
	//육지에서 가장 가까운 육지에 닿을때까지 BFS로 탐색진행하면 될듯
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> Map[i][j];
		}
	}
	
	int C = 2;
	
	//다리 탐색용 큐
	queue<pair<pair<int,int>,int>>Q;	//x,i,len
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(Map[i][j]==1){
				Map[i][j] = C;
				queue<pair<int,int>>M;
				Q.push(make_pair(make_pair(i,j),0));
				M.push(make_pair(i,j));
				while(!M.empty()){
					int x = M.front().first;
					int y = M.front().second;
					M.pop();
					for(int k=0;k<4;k++){
						int tx = x+dx[k];
						int ty = y+dy[k];
						if(tx>=0&&ty>=0&&tx<N&&ty<N){
							//탐색하려는 지역이 육지인 경우 섬번호 매겨주기
							if(Map[tx][ty]==1){
								Map[tx][ty] = Map[x][y];
								M.push(make_pair(tx,ty));
								Q.push(make_pair(make_pair(tx,ty),0));
							}
						}
					}
				}
				//대륙의 탐색이 끝나면 C늘려주기
				C++;
			}
		}
	}
	
	
	//i,j,len
	while(!Q.empty()){
		int i = Q.front().first.first;
		int j = Q.front().first.second;
		int len = Q.front().second;
		Q.pop();
		
		//cout << i << " " << j << "\n";
		
		int flag = 0;
		
		for(int k=0;k<4;k++){
			int tx = i + dx[k];
			int ty = j + dy[k];
			if(tx>=0&&ty>=0&&tx<N&&ty<N){
				//방문하지 않은 바다인 경우
				if(Map[tx][ty]==0){
					Map[tx][ty] = Map[i][j];
					CK[tx][ty] = len+1;
					Q.push(make_pair(make_pair(tx,ty),len+1));
				}
				//현재 탐색중인 대륙이 아닌 다른 대륙을 만난 경우
				else if(Map[tx][ty]!=Map[i][j]){
					if(result>len+CK[tx][ty])result = len+CK[tx][ty];
				}
			}
		}
	}
	
	cout << result << "\n";

}
