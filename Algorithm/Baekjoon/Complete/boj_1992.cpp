#include <bits/stdc++.h>

using namespace std;

void init();
bool CK(int x,int y,int N);
void Quad(int x,int y,int N);

int dx[4] = {0,0,1,1};
int dy[4] = {0,1,0,1};

int N;
char V[64][64];

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
			cin >> V[i][j];
		}
	}
	
	Quad(0,0,N);
	
}

void Quad(int x,int y,int N){
	if(CK(x,y,N)){
		cout << V[x][y];
	}
	else{
		cout << "(";
		for(int i=0;i<4;i++){
			Quad(x+dx[i]*N/2,y+dy[i]*N/2,N/2);
		}
		cout << ")";
	}
	
}

bool CK(int x,int y,int N){
	char C = V[x][y];
	
	for(int i=x;i<x+N;i++){
		for(int j=y;j<y+N;j++){
			if(C!=V[i][j])return false;
		}
	}
	
	return true;
}


