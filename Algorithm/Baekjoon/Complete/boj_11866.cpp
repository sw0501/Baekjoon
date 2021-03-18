#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

queue<int>Q;
int N;
int K;

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		Q.push(i);
	}
	int C=1;
	cout << "<";
	while(!Q.empty()){
		if(C==K){
			if(Q.size()!=1)cout << Q.front() << ", ";
			else cout << Q.front();
			Q.pop();
			C=1;
		}
		else{
			int temp = Q.front();
			Q.pop();
			Q.push(temp);
			C++;
		}
	}
	cout << ">\n";
}
