#include <bits/stdc++.h>

using namespace std;

void init();

int K;
stack<int>st;
long long ans = 0;


int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> K;
	for(int i=0;i<K;i++){
		int num;
		cin >> num;
		if(num==0)
			st.pop();
		else st.push(num);
	}
	while(!st.empty()){
		ans += st.top();
		st.pop();
	}
	cout << ans << "\n";
}
