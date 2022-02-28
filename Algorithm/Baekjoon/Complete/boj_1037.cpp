#include <bits/stdc++.h>

using namespace std;

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	long long N;
	vector<long long>v;
	cin >> N;
	for(int i=0;i<N;i++){
		long long num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	cout << v[0]*v[v.size()-1] << "\n";
}
