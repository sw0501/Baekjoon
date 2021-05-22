#include<iostream>
#include<algorithm>

using namespace std;

int N,M;
string str[1000001];
string ans[500001];

void init();

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
		cin >> str[i];
	}
	for(int i=N;i<N+M;i++){
		cin >> str[i];
	}
	
	sort(str,str+N+M);
	
	int C=0;
	
	for(int i=0;i<N+M;i++){
		if(str[i+1]==str[i]){
			ans[C] = str[i++];
			C++;
		}
	}
	
	cout << C << "\n";
	for(int i=0;i<C;i++){
		cout << ans[i] << "\n";
	}
	
}
