#include<iostream>
#include<algorithm>

using namespace std;

int N;
int K;
long long AR[5000000];

void init();

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	return 0;
}

void init(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> AR[i];
	}
	
	sort(AR,AR+N);
	
	cout << AR[K-1] << "\n";
}
