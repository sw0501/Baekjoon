#include <bits/stdc++.h>

using namespace std;

void init();

map<string,string>m;
int N,M;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		string s1,s2;
		cin >> s1 >> s2;
		m.insert({s1,s2});
	}
	for(int i=0;i<M;i++){
		string str;
		cin >> str;
		cout << m.find(str)->second << "\n";
	}
}
