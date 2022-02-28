#include <bits/stdc++.h>

using namespace std;

void init();
int BFS(vector<vector<int>>&V,int start);

int T;
int N;
int CK[1001];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> T;
	for(int t=0;t<T;t++){
		
		cin >> N;
		
		fill(CK,CK+N+1,0);
		vector<vector<int>>V(N+1);
		
		for(int i=1;i<=N;i++){
			int num;
			cin >> num;
			V[i].push_back(num);
		}
		
		int ans = 0;
		
		for(int i=1;i<=N;i++){
			if(CK[i]==0){
				ans += BFS(V,i);
			}
		}
		
		cout << ans << "\n";
	}
}

int BFS(vector<vector<int>>&V,int start){
	queue<int>Q;
	Q.push(start);
	int Cycle = 0;
	
	CK[start]=1;
	
	while(!Q.empty()){
		int index = Q.front();
		Q.pop();
		
		CK[V[index][0]]=1;
		
		if(V[index][0]==start){
			Cycle = 1;
			break;
		}
		else{
			Q.push(V[index][0]);
		}
	}
	return Cycle;
}