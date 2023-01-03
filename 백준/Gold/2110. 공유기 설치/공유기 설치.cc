#include <bits/stdc++.h>

using namespace std;

void init();

int N,C;
vector<long long>H;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> C;
	for(int i=0;i<N;i++){
		long long hx;
		cin >> hx;
		H.push_back(hx);
	}
	
	sort(H.begin(),H.end());
	long long left = 1;
	long long right = H[H.size()-1]-H[0];
	long long term = 0;
	long long ans = 0;
	
	//공유기간 간격을 기준으로 이분탐색 진행
	//1 ~ H[N-1]-H[0] 최대 거리를 찾을 때까지 진행
	while(left<=right){
		long long mid = (left+right)/2;
		int start = H[0];
		int cnt = 1;
		
		for(int i=1;i<N;i++){
			 term = H[i] - start;
			if(mid <= term){
				++cnt;
				start = H[i];
			}
		}
		
		if(cnt >= C){
			ans = (mid>ans?mid:ans);
			left = mid + 1;
		}
		else {
			right = mid -1;
		}
		
	}
	cout << ans << "\n";
}