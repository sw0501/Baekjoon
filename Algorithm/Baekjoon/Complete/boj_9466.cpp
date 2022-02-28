#include <bits/stdc++.h>

using namespace std;

void init();
int BFS(vector<vector<int>>&V,int start,int Cycle);
void DFS(vector<vector<int>>&V,int index,int Cycle);

int T;
int N;
int CK[100001];
int ans;
vector<vector<int>>V;

int main(){
	
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	init();
	
	
	return 0;
}

void init(){
	cin >> T;
	
	for(int t = 0;t<T;t++){
		fill(CK,CK+N+1,0);
		ans = 0;
		cin >> N;
		vector<vector<int>>V(N+1);
		for(int i=1;i<=N;i++){
			int num;
			cin >> num;
			V[i].push_back(num);
		}
		
		for(int i=1;i<=N;i++){
			if(CK[i]==0){
				DFS(V,i,i);
			}
			
		}
		cout << N-ans << "\n";
	}
}

void DFS(vector<vector<int>>&V,int index,int Cycle){

	CK[index] = Cycle;
	
	//방문하지 않은 정점인 경우 탐색 진행
	if(CK[V[index][0]]==0){
		DFS(V,V[index][0],Cycle);
	}
	//사이클이 완성된 경우
	else if(CK[V[index][0]]==Cycle){
		int temp = V[index][0];
		while(temp!=index){
			ans++;
			temp = V[temp][0];
		}
		//자기자신도 포함
		ans++;
	}
}
