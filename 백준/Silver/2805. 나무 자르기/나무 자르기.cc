#include <bits/stdc++.h>

using namespace std;

void init();

long long N,M;
vector<long long>T;

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
		long long temp;
		cin >> temp;
		T.push_back(temp);
	}
	
	//정렬
	sort(T.begin(),T.end());
	reverse(T.begin(),T.end());
	
	long long height = 0;
	//나무를 전부 다 자르는 경우 , 1미터만 가져가는 경우
	long long left=0,right=T[0];
	while(left<right){
		long long mid = (left+right)/2;
		long long cnt = 0;
		for(int i=0;i<T.size();i++){
			long long length = T[i] - mid;
			if(length>0){
				cnt += length;
			}
		}
		//cout << left << " " << mid << " " << right << " " << cnt << "\n";
		if(cnt>=M){
			left = mid+1;
			height = (mid>height?mid:height);
		}
		else{
			right = mid;
		}
		
	}
	
	cout << height << "\n";
	
}
