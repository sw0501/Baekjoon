#include <bits/stdc++.h>

using namespace std;

void init();
void DFS(int node,int len);

int CK[100001]={0,};
int V;
int End;
int Result = 0;
vector<pair<int,int>>T[100001];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> V;
	for(int i=0;i<V;i++){
		int parent, leaf, len;
		cin >> parent;
		cin >> leaf;
		while(leaf!=-1){
			cin >> len;
			T[parent].push_back(make_pair(leaf,len));
			T[leaf].push_back(make_pair(parent,len));
			cin >> leaf;
		}
	}
	
	DFS(1,0);
	fill(CK,CK+100001,0);
	DFS(End,0);
	cout << Result;
}

void DFS(int node,int len){
	CK[node]=1;
	
	if(Result<len){
		Result = len;
		End = node;
	}
	
	for(int i=0;i<T[node].size();i++){
		if(CK[T[node][i].first]==0)DFS(T[node][i].first,len+T[node][i].second);
	}
}