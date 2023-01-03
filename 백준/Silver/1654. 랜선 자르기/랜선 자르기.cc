#include<iostream>
#include<algorithm>

using namespace std;

void init();
int binary_search();

int K,N;
long long lan[10000];
int main(){
	
	//ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> K >> N;
	for(int i=0;i<K;i++){
		cin >> lan[i];
	}
	
	sort(lan,lan+K);
	reverse(lan,lan+K);
	//1 ~ lan[0] 사이에서 이분탐색 진행
	binary_search();
}

int binary_search(){
	
	long long left = 1;
	long long right = lan[0];
	int max = -1;
	
	while(left<=right){
		
		long long answer = 0;
		long long mid = (left+right)/2;
		for(int i=0;i<K;i++){
			answer += (lan[i]/mid);
		}
		//cout <<left << " " << mid << " " << right << " " << answer << "\n";
		//getchar();
		//랜선이 부족하다면 더 작은 길이 선택
		if(answer<N){
			right = mid-1;
		}
		else {
			max = (mid>max?mid:max);
			//랜선이 충분하다면 길이에 따른 비교
			left = mid+1;
		}
		
	}
	cout << max << "\n";
	return 0;
}
