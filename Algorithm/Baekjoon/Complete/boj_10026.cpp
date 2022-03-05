#include <bits/stdc++.h>

using namespace std;

void init();


int N;
char arr[100][100];
int CK[100][100]={0,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

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
		for(int j=0;j<N;j++){
			cin >> arr[i][j];
		}
	}
	
	queue<pair<int,int>>q;
	
	int answer = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(CK[i][j]==0){
				//cout << i << " " << j << "\n";
				q.push(make_pair(i,j));
				CK[i][j] = 1;
				answer++;
				while(!q.empty()){
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for(int k=0;k<4;k++){
						int tx = x+dx[k];
						int ty = y+dy[k];
						if(tx>=0&&tx<100&&ty>=0&&ty<100){
							if(CK[tx][ty]==0&&arr[x][y]==arr[tx][ty]){
								CK[tx][ty] = 1;
								q.push(make_pair(tx,ty));
							}
						}
					}
				}
			}
		}
	}
	
	cout << answer << " ";
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(arr[i][j]=='G')arr[i][j]='R';
		}
	}
	
	fill(CK[0],CK[100],0);
	
	answer = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(CK[i][j]==0){
				//cout << i << " " << j << "\n";
				q.push(make_pair(i,j));
				CK[i][j] = 1;
				answer++;
				while(!q.empty()){
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for(int k=0;k<4;k++){
						int tx = x+dx[k];
						int ty = y+dy[k];
						if(tx>=0&&tx<100&&ty>=0&&ty<100){
							if(CK[tx][ty]==0&&arr[x][y]==arr[tx][ty]){
								CK[tx][ty] = 1;
								q.push(make_pair(tx,ty));
							}
						}
					}
				}
			}
		}
	}
	
	
	cout << answer << "\n";
	
}