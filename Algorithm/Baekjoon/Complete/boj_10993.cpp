#include <bits/stdc++.h>

using namespace std;

void init();
void star(int n,int x,int y);
void reverse(int n,int x,int y);

int N;
int H=1;
char arr[2048][4094];

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
	
	
	if(N==1)cout << "*";
	else{
		for(int i=1;i<N;i++){
			H = 2*H+1;
		}
		
		fill(arr[0],arr[H],' ');
		
		if(N%2==0){
			reverse(H,H-1,H-1);
		}
		else{
			star(H,H-1,0);
		}
		
		if(N%2==1){
			for(int i=0;i<H;i++){
				for(int j=0;j<=H+i;j++){
					cout << arr[i][j];
				}
				cout << "\n";
			}
		}
		else{
			for(int i=H-1;i>=0;i--){
				for(int j=0;j<=H+i;j++){
					cout << arr[H-i-1][j];
				}
				cout << "\n";
			}
		}
	}
}

void star(int n,int x,int y){
	for(int i=0;i<n;i++){
		if(i==n-1){
			//마지막 줄인 경우
			for(int j=x-n;j<x+n;j++){
				arr[y+i][j]='*';
			}
		}
		else{
			arr[y+i][x-i]='*';
			arr[y+i][x+i]='*';
		}
	}
	reverse(n/2,x,y+n-2);
}

void reverse(int n,int x,int y){
	if(n==3){
		arr[y][x] = '*';
		arr[y-1][x-1] = '*';
		arr[y-1][x] = '*';
		arr[y-1][x+1] = '*';
		arr[y-2][x-2] = '*';
		arr[y-2][x-1] = '*';
		arr[y-2][x] = '*';
		arr[y-2][x+1] = '*';
		arr[y-2][x+2] = '*';
	}
	else{
		for(int i=0;i<n;i++){
			if(i==n-1){
				//마지막 줄인 경우
				for(int j=x-n;j<x+n;j++){
					arr[y-i][j]='*';
				}
			}
			else{
				arr[y-i][x-i]='*';
				arr[y-i][x+i]='*';
			}
		}
		star(n/2,x,y-n+2);
	}
}
