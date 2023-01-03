#include <bits/stdc++.h>

using namespace std;

void init();
void BFS();

int N,M;
vector<int>v[101];
int vacon = -1;
int ans = 100000000;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int n1,n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	
	for(int i=1;i<=N;i++){
		int answer = 0;
		queue<pair<int,int>>Q;
		Q.push(make_pair(i,0));
		int CK[101]={0,};
		CK[i] = 1;
		while(!Q.empty()){
			int num = Q.front().first;
			int kevin = Q.front().second;
			answer += kevin;
			Q.pop();
			for(int i=0;i<v[num].size();i++){
				//체크하지 않은 수라면 큐에 삽입
				if(CK[v[num][i]]==0){
					Q.push(make_pair(v[num][i],kevin+1));
					CK[v[num][i]] = 1;
				}
			}
		}
		if(ans>answer){
			vacon = i;
			ans = answer;
		}
	}
	cout << vacon << "\n";
}
