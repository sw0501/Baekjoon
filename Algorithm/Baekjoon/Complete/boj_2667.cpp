#include <bits/stdc++.h>

using namespace std;

void init();
void DFS(int x,int y);

char CK[26][26]={0,};
int N;
int ans;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<int>H;	//단지수

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	
	cin >> N;
	
	fill(CK[0],CK[0]+N,0);
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> CK[i][j];
		}
	}
	
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(CK[i][j]!='0'){
				ans = 0;
				DFS(i,j);
				H.push_back(ans);
			}
		}
	}
	
	sort(H.begin(),H.end());
	cout << H.size() << "\n";
	for(int i=0;i<H.size();i++){
		cout << H[i] << "\n";
	}
}

void DFS(int x,int y){
	//단지 확인 후 수 카운트
	CK[x][y] = '0';
	ans++;
	
	for(int i=0;i<4;i++){
		int tx = x+dx[i];
		int ty = y+dy[i];
		
		//탐색가능한 범위인 경우
		if(tx>=0&&ty>=0&&tx<N&&ty<N){
			//단지가 있는 경우
			if(CK[tx][ty]=='1')DFS(tx,ty);
		}
	}
}
