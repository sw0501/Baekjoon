#include <bits/stdc++.h>

using namespace std;

void init();
void Paper(int x,int y,int N);
bool CK(int x,int y,int N);	
int N;
int P[2500][2500];
int ans[3] = {0,};

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	//처음 입력받을 때 종이가 전부 채워여있는지 확인하고 그렇지 않다면 9부분으로 나눠서
	//모두 다 같은 칸인 경우엔 1 return 그렇지 않다면 다시 9부분으로 나눠 탐색을 진행
	cin >> N;
	
	int flag = 1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> P[i][j];	
		}
	}
	
	Paper(0,0,N);
	
	for(int i=0;i<3;i++){
		cout << ans[i] << "\n";
	}
}

void Paper(int x,int y,int N){
	if(CK(x,y,N))ans[P[x][y]+1]++;
	else{
		for(int i=x;i<x+N;i+=N/3){
			for(int j=y;j<y+N;j+=N/3){
				Paper(i,j,N/3);
			}
		}
	}
}

bool CK(int x,int y,int N){
	int num = P[x][y];
	for(int i=x;i<x+N;i++){
		for(int j=y;j<y+N;j++){
			if(num!=P[i][j])return false;
		}
	}
	return true;
}