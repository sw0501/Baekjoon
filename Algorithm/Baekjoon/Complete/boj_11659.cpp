#include<bits/stdc++.h>

using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M;
	vector<int>v;
	v.push_back(0); //1부터 구할 때 필요
	
	cin >> N >> M;
	
	int num = 0;
	
	for(int i=0;i<N;i++){
		cin >> num;
		num += v[i];
		v.push_back(num);
		
	}
	
	for(int m=0;m<M;m++){
		int i,j;
		cin >> i >> j;
		cout << v[j]-v[i-1] << "\n";
	}
	
	
	
	return 0;
}