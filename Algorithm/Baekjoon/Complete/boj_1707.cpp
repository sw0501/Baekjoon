#include <bits/stdc++.h>

using namespace std;

void init();
void BFS(vector<vector<int>>&B,int index);


int K,V,E;
vector<int> B[20001];
int Color[20001];
int Binary_Graph;


int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> K;
	for(int k=0;k<K;k++){
		
		cin >> V >> E;
		
		vector<vector<int>>B(V+1);
		
		//Color[1] ~ Color[V]까지 0로 초기화
		fill(Color,Color+V+1,0);
		int flag = 0;
		for(int i=0;i<E;i++){
			int num, line;
			cin >> num >> line;
			//양쪽 간선 연결
			B[num].push_back(line);
			B[line].push_back(num);
		}
		
		Binary_Graph = 1;
		
		for(int i=1;i<=V;i++){
			if(Binary_Graph==0)break;
			
			if(Color[i]==0){
				BFS(B,i);
			}
		}
		
		if(Binary_Graph)cout << "YES" << "\n";
		else cout << "NO" << "\n";
		
	}
}

void BFS(vector<vector<int>>&B,int index){
	queue<int>Q;
	
	//시작 정점 큐에 삽입
	Q.push(index);
	Color[index] = 1;
	
	//큐가 비어있지 않고 이분 그래프인 경우 반복
	while(!Q.empty()&&Binary_Graph){
		int ver = Q.front();
		Q.pop();
		//시작 정점 색
		int C = Color[ver];
		
		//정점과 연결된 간선들 탐색
		for(int i=0;i<B[ver].size();i++){
			//탐색하지 않은 정점이라면 색 저장
			if(Color[B[ver][i]]==0){
				Color[B[ver][i]] = C*(-1);
				Q.push(B[ver][i]);
			}
			//탐색 한 정점이라면 이미 칠해져 있는 색과 일치하는지 비교
			else{
				if(Color[B[ver][i]]==C){
					Binary_Graph = 0;
					break;
				}
			}
		}
	}
}
