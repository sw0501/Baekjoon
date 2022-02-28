#include<iostream>
#include<algorithm>

using namespace std;

int N;
int S;
int arr[100001];

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	cin >> S;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	
	init();
	
	
	return 0;
}

void init(){
	
	//S이상이 될때까지 합 구하다가 된 경우에 맨앞의 포인터를 당겨서 S이하가 될때까지 반복
	
	int *p1 = arr;
	int *p2 = arr;
	
	int sum = arr[0];
	int ans = N;
	int flag = 0;
	
	if(sum>=S){
		flag =1;
		ans = 1;
	}
	else{
		for(int i=1;i<N;i++){
			p2++;
			sum += *p2;
			if(sum>=S){
				flag = 1;
				while(sum-*p1>=S){
					sum -= *p1;
					p1++;
				}
				ans = (ans>p2-p1+1?p2-p1+1:ans);
			}
		}
	}
	
	
	if(flag)cout << ans << "\n";
	else cout << 0 << "\n";
	
	
	
}
