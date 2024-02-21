#include<iostream>

using namespace std;

int N;				
int arr[4000000]={0,};	//배열 저장
int list[4000000]={0,};	//DP 역할
int li[4000000]={0,};	//LIS 개수 저장 배열
int lis[4000000];		//LIS 저장

int binary_search(int left,int right,int target);	//이분탐색
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
	int id=0;	//가장 큰 LIS의 인덱스
	int M=0;	//가장 큰 LIS의 개수
	
	//비어있는 리스트에 0번째 숫자 넣기
	list[0] = arr[0];
	
	//li[i]가 맥스인 곳을 찾은 후에
	for(int i=0;i<N;i++){
		//숫자가 [j]보다 크다면 [j+1]에 저장, li에 개수 저장
		if(arr[i]>list[j]){
			list[j+1]=arr[i];
			j+=1;
			li[i]=j+1;
		}
		//작다면 어디에 들어가야할 지 이분탐색으로 찾은 후 해당 위치에 저장, li[i]에 LIS 개수 저장
		else {
			int idx = binary_search(0,j,arr[i]);
			list[idx] = arr[i];
			li[i]=idx+1;
		}
		//비교하여 가장 큰 LIS인 경우 저장
		if(li[i]>M){
			M=li[i];
			id = i;
		}
	}
	cout << j+1 << "\n";
	
	int c = 0;
	//LIS 마지막 인덱스부터 시작하여 줄여나가면서 출력
	for(int i=id;i>=0;i--){
		if(li[i]==li[id]){
			lis[c++]=arr[i];
			li[id]--;
		}
	}
	for(int i=c-1;i>=0;i--){
		cout << lis[i] << " ";
	}
}


