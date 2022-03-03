#include<bits/stdc++.h>

using namespace std;

int game[101] = {0,};

int CK[101] = {0,};

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M;
	cin >> N >> M;
	
	int item,move;
	for(int i=0;i<N;i++){
		cin >> item >> move;
		game[item] = move;
	}
	for(int i=0;i<M;i++){
		cin >> item >> move;
		game[item] = move;
	}
	
	queue<pair<int,int>>q;
	q.push(make_pair(1,0));
	while(!q.empty()){
		int board = q.front().first;
		int C = q.front().second;
		CK[board]=1;
		q.pop();
		
		//주사위 굴리기
		for(int i=1;i<=6;i++){
			if(CK[board+i])continue;
			if(board+i==100){
				cout << C+1 << "\n";
				return 0;
			}
			else if(board+i>100)break;
			
			CK[board+i]=1;
			//뱀이나 사다리 칸이라면 올라간 곳 큐에 저장
			if(game[board+i]!=0)q.push(make_pair(game[board+i],C+1));
			//아니라면 해당칸으로 전진
			else q.push(make_pair(board+i,C+1));
		}
	}
	
	return 0;
}