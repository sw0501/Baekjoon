#include<iostream>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

int N;
int M;
int K;
char Board[110][110] = {' ',};
string Word;
queue<pair<int,int>> q;

void init();
int DFS(int x,int y,int C);
int BFS(int x,int y,int C);

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
			cin >> Board[i+5][j+5];
		}
	}
	cin >> Word;
	
	int ans = 0;
	/*
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(Board[i+5][j+5]==Word[0]){
				//ans += DFS(i+5,j+5,1);
				//q.push(make_pair(i+5,j+5));
				//BFS();
			}
		}
	}*/
	
	/*
	for(int i=Word.length()-1;i>=0;i--){
		for(int j=0;j<N;j++){
			
		}
	}
	*/
	
	cout << Word.length() << "\n";
}

int DFS(int x,int y,int C){
	int ans = 0;
	for(int i=1;i<=K;i++){
		//마지막 문자일 경우
		if(C==Word.size()-1){
			if(Board[x+i][y]==Word[C]){
				ans++;
			}
			if(Board[x-i][y]==Word[C]){
				ans++;
			}
			if(Board[x][y+i]==Word[C]){
				ans++;
			}
			if(Board[x][y-i]==Word[C]){
				ans++;
			}
		}
		else{
			if(Board[x+i][y]==Word[C]){
				ans += DFS(x+i,y,C+1);
			}
			if(Board[x-i][y]==Word[C]){
				ans += DFS(x-i,y,C+1);
			}
			if(Board[x][y+i]==Word[C]){
				ans += DFS(x,y+i,C+1);
			}
			if(Board[x][y-i]==Word[C]){
				ans += DFS(x,y-i,C+1);
			}
		}
	}
	return ans;
}

/*
int BFS(int x,int y,int C){
	int ans = 0;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=1;i<=K;i++){
			
		}
	}
}
*/
