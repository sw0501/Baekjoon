#include <bits/stdc++.h>

using namespace std;

void init();
void star(int x,int y,int n);

int N;
char arr[500][500];


int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	
	fill(arr[0],arr[500],' ');
	
	star(0,0,N);
	//1 5 9 13
	//가로세로 : 1+ 4*(N-1)
	//중간 별 위치 : 중간 
	
	for(int i=0;i<4*(N-1)+1;i++){
		for(int j=0;j<4*(N-1)+1;j++){
			cout << arr[i][j];
		}
		cout << "\n";
	}
}

void star(int x,int y,int n){
	for(int i=0;i<4*(n-1)+1;i++){
		if(i==0||i==4*(n-1)){
			for(int j=0;j<4*(n-1)+1;j++){
				arr[y+i][x+j]='*';
			}
		}
		else{
			arr[y+i][x] = '*';
			arr[y+i][x+4*(n-1)]='*';
		}
	}
	if(n!=1)star(x+2,y+2,n-1);
}
