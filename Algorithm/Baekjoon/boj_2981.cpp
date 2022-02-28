#include <bits/stdc++.h>

using namespace std;

void init();

long long N,M=2;
long long arr[100];
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	sort(arr,arr+N);
	
	for(int i=1;i<N;i++){
		arr[i] = arr[i] - arr[0];
	}
	
	
}
