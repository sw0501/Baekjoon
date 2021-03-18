#include<iostream>

using namespace std;

int N=0;				
int arr[1001]={0,};	//배열 저장
int list_up[1001]={0,};	//증가 수열 DP 역할
int list_down[1001]={0,};//감소 수열 DP 역할
int Bitonic[1001]={0,};	//바이토닉 수열 개수

int idx=0;

int binary_search_up(int left,int right,int target);	//이분탐색
int binary_search_down(int left,int right,int target);	//이분탐색

void init();

int main(){
	
	init();
	
	return 0;
}

//배열 2개에 저장하므로 함수 2개 또는 인자에 어떤 배열 사용할건지 적어놓자

int binary_search_up(int left,int right,int target){
	//위치를 찾을 때까지
	while(left<right){
		//분할 지점
		int mid = (left+right)/2;
		//저장할 수가 분할 지점 수보다 크다면
		if(target>list_up[mid]){
			left = mid+1;
		}
		else {
			right = mid;
		}
	}
	return right;
}

int binary_search_down(int left,int right,int target){
	//위치를 찾을 때까지
	while(left<right){
		//분할 지점
		int mid = (left+right)/2;
		//저장할 수가 분할 지점 수보다 크다면
		if(target>list_down[mid]){
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
	int j=0;	//수열 크기
	//비어있는 리스트에 0번째 숫자 넣기
	list_up[0] = arr[0];
	
	//증가와 감소수열을 각각 구하여 서로 더했을때 가장 큰 것이 가장 큰 바이토닉 부분수열 개수 (증가수열과 감소수열의 교차점을 찾으면 됨)
	for(int i=0;i<N;i++){
		//숫자가 [j]보다 크다면 [j+1]에 저장
		if(arr[i]>list_up[j]){
			idx = i;
			list_up[j+1]=arr[i];
			j+=1;
		}
		//작다면 어디에 들어가야할 지 이분탐색으로 찾은 후 해당 위치에 저장
		else {
			idx = binary_search_up(0,j,arr[i]);
			list_up[idx] = arr[i];
		}
		Bitonic[i]=j;
	}
	
	//감소 수열 
	j=0;
	int M=0;
	list_down[0] = arr[N-1];
	for(int i=N-1;i>=0;i--){
		//숫자가 arr[k]보다 크다면 [j+1]에 저장
		if(arr[i]>list_down[j]){
			idx = i;
			list_down[j+1]=arr[i];
			j+=1;
		}
		//작다면 어디에 들어가야할 지 이분탐색으로 찾은 후 해당 위치에 저장
		else {
			idx = binary_search_down(0,j,arr[i]);
			list_down[idx] = arr[i];
		}
		Bitonic[i]+=j;
		if(Bitonic[i]>M)M=Bitonic[i];
	}
	
	cout << M+1 << "\n";
	
}

