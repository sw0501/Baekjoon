#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N;
queue<int> Q;

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	for(int i=1;i<=N;i++){
		Q.push(i);
	}
	while(Q.size()!=1){
		Q.pop();
		int x = Q.front();
		Q.pop();
		Q.push(x);
	}
	cout << Q.front() << "\n";
}
