#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	while(1){
		int n,m;
		cin >> n >> m;
		if(n==0&&m==0)break;
		if(n%m==0)cout << "multiple\n";
		else if(m%n==0) cout << "factor\n";
		else cout << "neither\n";
	}
}
