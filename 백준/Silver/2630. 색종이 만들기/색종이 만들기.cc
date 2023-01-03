#include <bits/stdc++.h>

using namespace std;

void init();
void Div(int x,int y,int n);

int N;
int arr[128][128];
int answer[2] = {0,};
int dx[4] = {0,0,1,1};
int dy[4] = {0,1,0,1};

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
	Div(0,0,N);
	
	cout << answer[0] << "\n" << answer[1] << "\n";
}

void Div(int x,int y,int n){
	//첫번째 블럭을 지정
	int flag = arr[x][y];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[x+i][y+j]!=flag){
				flag = -1;
				for(int t=0;t<4;t++){
					int tx = x+dx[t]*n/2;
					int ty = y+dy[t]*n/2;
					Div(tx,ty,n/2);
				}
				//분할하여 종이 개수 파악 진행했으므로 종료
				return ;
			}
		}
	}
	
	if(flag!=-1){
		answer[flag]++;
	}
}