#include <bits/stdc++.h>

using namespace std;

void init();

int N;
char arr[1000][1000];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	 
	fill(arr[0],arr[1000],' ');
	
	//x : 4*N - 3
	//y : 2*N - 1
	
	for(int i=0;i<N;i++){
		for(int j=i;j<i+N;j++){
			if(i==0||(j==i||j==i+N-1)){
				arr[i][j] = '*';
				arr[i][4*N-4-j] = '*';
			}
		}
	}
	for(int i=N;i<2*N-1;i++){
		for(int j=2*N-2-i;j<2*N-2-i+N;j++){
			if(i==2*N-2||(j==2*N-2-i||j==2*N-2-i+N-1)){
				arr[i][j] = '*';
				arr[i][4*N-4-j] = '*';
			}
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<4*N-3-i;j++){
			cout << arr[i][j];
		}
		cout << "\n";
	}
	for(int i=N;i<2*N-1;i++){
		for(int j=0;j<4*N-3-(2*N-2-i);j++){
			cout << arr[i][j];
		}
		cout << "\n";
	}
}
