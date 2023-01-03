#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int K;

int T[200001] = {0,};
int visit_BFS[200001] = {0,};

void init();
void BFS(int N);

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	int N;
	cin >> N >> K;
	
	BFS(N);
	
}

void BFS(int N){
	queue<int>point;
	point.push(N);
	while(!point.empty()){
		int temp = point.front();
		point.pop();
		visit_BFS[temp]=1;
		if(0<=temp-1){
			if(visit_BFS[temp-1]==0){
				visit_BFS[temp-1]=1;
				T[temp-1]=T[temp]+1;
				point.push(temp-1);
			}
		}
		if(0<=temp+1&&temp+1<=2*K){
			if(visit_BFS[temp+1]==0){
				visit_BFS[temp+1]=1;
				T[temp+1]=T[temp]+1;
				point.push(temp+1);
			}
		}
		if(0<=temp*2&&temp*2<=2*K){
			if(visit_BFS[temp+temp]==0){
				visit_BFS[temp+temp]=1;
				T[temp+temp]=T[temp]+1;
				point.push(temp*2);
			}
		}
	}
	
	cout << T[K] << "\n";
}

