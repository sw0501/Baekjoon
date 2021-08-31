#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int S;
int answer = 0;
vector<int>V;


void init();
void DFS(int sum,int idx);

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	cin >> S;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		V.push_back(num);
	}
	DFS(0,0);
	cout << answer << "\n";
}

void DFS(int sum,int idx){
	for(int i=idx;i<V.size();i++){
		sum+=V[i];
		if(sum==S)answer++;
		DFS(sum,i+1);
		sum-=V[i];
	}
}