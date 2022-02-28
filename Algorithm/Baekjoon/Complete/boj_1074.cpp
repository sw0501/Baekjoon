#include <bits/stdc++.h>

using namespace std;

void init();
void Div(int x,int y,int n);

int N,r,c;	//r행 c열
long long ans = 0;
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
	cin >> N >> r >> c;
	
	int temp = 1;
	for(int i=0;i<N;i++){
		temp*=2;
	}
	Div(0,0,N);
	
}

void Div(int x,int y,int n){
	if(n==1){
		for(int i=0;i<4;i++){
			if(x+dx[i]==r&&y+dy[i]==c){
				cout << ans << "\n";
			}
			ans++;
		}
	}
	else{
		int num = 1;
		for(int i=0;i<n-1;i++){
			num*=2;
		}
		for(int i=0;i<4;i++){
			int tx = x+dx[i]*num;
			int ty = y+dy[i]*num;
			if(r>=tx&&r<tx+num&&c>=ty&&c<ty+num){
				Div(tx,ty,n-1);
			}
			else ans += num*num;
		}
	}
}
