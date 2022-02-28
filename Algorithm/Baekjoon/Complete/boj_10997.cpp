#include <bits/stdc++.h>

using namespace std;

void init();
void star(int x,int y,int n,int d);

int N;
char arr[1500][1500];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main(){
	
	/*
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	fill(arr[0],arr[1500],' ');
	
	if(N==1)cout << "*";
	
	else{
		for(int i=0;i<4*(N-1)+3;i++){
			arr[i][0] = '*';
		}
		for(int i=0;i<4*(N-1)+1;i++){
			arr[0][i] = '*';
		}
		
		star(0,4*(N-1)+2,4*(N-1)+1,0);
		for(int i=0;i<=4*(N-1)+2;i++){
			if(i==1){
				cout << "*\n";
			}
			else{
				for(int j=0;j<=4*(N-1);j++){
					cout << arr[i][j];
				}
				cout << "\n";
			}
			
		}
		
	}
	
	
	
}

void star(int x,int y,int n,int d){
	
	if(n==1)return;
	
	int i = 0;
	while(i<n-1){
		y += dy[d];
		x += dx[d];
		arr[y][x] = '*';
		i++;
	}
	d++;
	if(d==4)d=0;
	i = 0;
	while(i<n-1){
		y += dy[d];
		x += dx[d];
		arr[y][x] = '*';
		i++;
	}
	d++;
	if(d==4)d=0;
	star(x,y,n-2,d);
}

