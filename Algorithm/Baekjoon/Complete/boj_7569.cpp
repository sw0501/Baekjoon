#include <bits/stdc++.h>

using namespace std;

void init();

struct Pos{
	int h;
	int m;
	int n;
	int d;
};

int M,N,H;
int arr[100][100][100]={0,};
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
	cin >> N >> M >> H;
	
	int answer = 0;
	queue<Pos>q;
	
	for(int h=0;h<H;h++){
		for(int m=0;m<M;m++){
			for(int n=0;n<N;n++){
				cin >> arr[h][m][n];
			}
		}
	}
	
	
	for(int h=0;h<H;h++){
		for(int m=0;m<M;m++){
			for(int n=0;n<N;n++){
				if(arr[h][m][n]==1){
					Pos temp = {h,m,n,0};
					q.push(temp);
				}
			}
		}
	}
	
	
	while(!q.empty()){
		for(int i=0;i<4;i++){
			int tx = q.front().m+dx[i];
			int ty = q.front().n+dy[i];
			if(tx>=0&&tx<M&&ty>=0&&ty<N){
				if(arr[q.front().h][tx][ty]==0){
					arr[q.front().h][tx][ty]=q.front().d+1;
					Pos pos = {q.front().h,tx,ty,q.front().d+1};
					q.push(pos);
					answer = (answer>pos.d?answer:pos.d);
				}
			}
		}
		if(q.front().h+1<H){
			if(arr[q.front().h+1][q.front().m][q.front().n]==0){
				arr[q.front().h+1][q.front().m][q.front().n] = q.front().d+1;
				Pos pos = {q.front().h+1,q.front().m,q.front().n,q.front().d+1};
				q.push(pos);
				answer = (answer>pos.d?answer:pos.d);
			}
		}
		if(q.front().h-1>=0){
			if(arr[q.front().h-1][q.front().m][q.front().n]==0){
				arr[q.front().h-1][q.front().m][q.front().n] = q.front().d+1;
				Pos pos = {q.front().h-1,q.front().m,q.front().n,q.front().d+1};
				q.push(pos);
				answer = (answer>pos.d?answer:pos.d);
			}
		}
		q.pop();
	}	
	
	//시간복잡도 생각하면 익지않은 토마토 개수 센다음 queue 처리할때 구해야됨
	//익지 않은 토마토가 있는 경우
	for(int h=0;h<H;h++){
		for(int m=0;m<M;m++){
			for(int n=0;n<N;n++){
				if(arr[h][m][n]==0){
					cout << "-1\n";
					return;
				}
			}
		}
	}
	
	cout << answer << "\n";
}
