#include <bits/stdc++.h>

using namespace std;

void init();

long long A,B;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> A >> B;
	queue<pair<long long,int>>Q;
	int flag = 1;
	Q.push(make_pair(A,1));
	
	while(!Q.empty()){
		
		long long num = Q.front().first;
		int answer = Q.front().second;
		Q.pop();
		if(num*10+1==B||num*2==B){
			flag = 0;
			cout << answer+1 << "\n";
			break;
		}
		if(num*10+1<B){
			Q.push(make_pair(num*10+1,answer+1));
		}
		if(num*2<B){
			Q.push(make_pair(num*2,answer+1));
		}
	}
	
	if(flag)cout << "-1\n";
}
