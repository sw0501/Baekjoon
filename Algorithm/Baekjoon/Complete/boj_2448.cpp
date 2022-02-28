#include <bits/stdc++.h>

using namespace std;

void init();
void star(int x,int y,int n);

int N;
char arr[3500][6500];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	
	//배열 초기화
	fill(arr[0],arr[3500],' ');
	
	//높이, x,y 좌표
	star(N-1,0,N);
	
	
	for(int i=0;i<N;i++){
		for(int j=0;j<=2*N-1;j++){
			cout << arr[i][j];
		}
		cout << "\n";
	}
	
}

void star(int x,int y,int n){
	//가장 작은 삼각형이라면 별 출력
	if(n==3){
		arr[y][x] = '*';
		arr[y+1][x-1] = '*';
		arr[y+1][x+1] = '*';
		arr[y+2][x-2] = '*';
		arr[y+2][x-1] = '*';
		arr[y+2][x] = '*';
		arr[y+2][x+1] = '*';
		arr[y+2][x+2] = '*';
	}
	
	//더 분할이 가능한 경우 더 작은 삼각형으로 분할
	else{
		//위쪽 삼각형
		star(x,y,n/2);
		//왼쪽 아래 삼각형
		star(x-n/2,y+n/2,n/2);
		//오른쪽 아래 삼각형
		star(x+n/2,y+n/2,n/2);
	}
}
