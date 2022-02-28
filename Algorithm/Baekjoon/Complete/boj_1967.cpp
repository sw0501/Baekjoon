#include <bits/stdc++.h>

using namespace std;

void init();
void DFS(int node,int len);

int N;
vector<pair<int,int>>V[100001];
int End=0;
int result=0;
int CK[100001] = {0,};

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
		int parent,leaf,length;
		cin >> parent;
		cin >> leaf;
		cin >> length;
		V[parent].push_back(make_pair(leaf,length));
		V[leaf].push_back(make_pair(parent,length));
	}
	
	DFS(1,0);
	fill(CK,CK+100001,0);
	DFS(End,0);
	cout << result << "\n";
}


void DFS(int node,int len){
	CK[node] = 1;
	
	//저장되어있는 지름보다 더 길다면 교체
	if(result<len){
		result = len;
		End = node;
	}
	
	for(int i=0;i<V[node].size();i++){
		//탐색하지 않은 노드인 경우 길이 비교 후 탐색 진행
		if(CK[V[node][i].first]==0){
			DFS(V[node][i].first,len+V[node][i].second);
		}
	}
}
