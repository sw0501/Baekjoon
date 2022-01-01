#include<iostream>
#include<algorithm>

using namespace std;

void init();
int binary_search();

int K,N;
double lan[10000];
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
	
	//1 ~ lan[0] 사이에서 이분탐색 진행
	binary_search();
}

int binary_search(){
	
	double left = 0;
	double right = lan[0];
	
	double flag1=-1;
	double flag2=-1;
	
	while(left<right){
		
		if(left == flag1 && right == flag2)break;
		
		flag1 = left;
		flag2 = right;
		
		int answer = 0;
		double mid = (left+right)/2;
		for(int i=0;i<K;i++){
			answer += (int)(lan[i]/mid);
		}
		//cout <<left << " " << mid << " " << right << " " << answer << "\n";
		//getchar();
		//랜선이 부족하다면 더 작은 길이 선택
		if(answer<N){
			right = mid;
		}
		else {
			//랜선이 충분하다면 길이에 따른 비교
			left = mid;
		}
		
		
		
	}
	cout << (int)left << "\n";
	return 0;
}
