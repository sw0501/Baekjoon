#include <bits/stdc++.h>

using namespace std;

void init();

int N;
int CK[100001] = {0,};
vector<int>V[100001];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	
	queue<int>Q;
	
	//루트 노드 1 큐에 삽입 후 방문 표시
	Q.push(1);
	CK[1]=1;
	
	while(!Q.empty()){
		int parent = Q.front();
		
		Q.pop();
		for(int i=0;i<V[parent].size();i++){
			//방문하지 않은 노드 -> 부모가 밝혀지지 않는 노드 탐색
			if(CK[V[parent][i]]==0){
				CK[V[parent][i]]=parent;
				Q.push(V[parent][i]);
			}
		}
	}
	
	for(int i=2;i<=N;i++){
		cout << CK[i] << "\n";
	}
}
