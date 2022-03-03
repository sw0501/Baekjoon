#include <bits/stdc++.h>

using namespace std;

void init();

int T,M,N,X,Y;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> T;
	for(int t=0;t<T;t++){
		cin >> M >> N >> X >> Y;
		long long ans = X;
		
		//N과M의 최대공약수
		int n=N,m=M;
		while(n!=0){
			int r = m%n;
			m = n;
			n = r;
		}
		long long limit = M*N/m;
		int flag = 1;
		while(ans<=limit){
			//나머지가 0인 케이스 고려
			if(ans%N==Y%N){
				flag = 0;
				cout << ans << "\n";
				break;
			}
			ans+=M;
		}
		if(flag) cout << -1 << "\n";
	}
	
	
}
