#include<iostream>

using namespace std;

int N;				
int arr[4000000];	//배열 저장
int list[4000000];	//DP 역할

int binary_search(int left,int right,int target);
void init();

int main(){
	
	init();
	
	return 0;
}

int binary_search(int left,int right,int target){
	//위치를 찾을 때까지
	while(left<right){
		//분할 지점
		int mid = (left+right)/2;
		//저장할 수가 분할 지점 수보다 크다면
		if(target>list[mid]){
			left = mid+1;
		}
		else {
			right = mid;
		}
	}
	return right;
}

void init(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	
	int j=0;	//배열 크기
	int c=0;	//수열 카운트
	
	//비어있는 리스트에 0번째 숫자 넣기
	list[0] = arr[0];
	for(int i=0;i<N;i++){
		//숫자가 [j]보다 크다면 [j+1]에 저장
		if(arr[i]>list[j]){
			list[j+1]=arr[i];
			j+=1;
		}
		//작다면 어디에 들어가야할 지 이분탐색으로 찾은 후 해당 위치에 저장
		else {
			int idx = binary_search(0,j,arr[i]);
			list[idx] = arr[i];
		}
	}
	
	cout << j+1 << "\n";
}
