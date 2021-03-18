#include<iostream>

using namespace std;

int N;
int Arr[1001]={0,};
int LIS[1001]={0,};
int L=0;

int binary_search(int left,int right,int target);
void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> Arr[i];
	}
	LIS[0] = Arr[N-1];
	//뒤에서부터 증가하는 수열을 찾아서 LIS 기록
	for(int i=N-1;i>=0;i--){
		if(Arr[i]>LIS[L]){
			LIS[L+1]=Arr[i];
			L++;
		}
		else{
			int idx = binary_search(0,L,Arr[i]);
			LIS[idx] = Arr[i];
		}
	}
	cout << L+1 << "\n";
}

int binary_search(int left,int right,int target){
	while(left<right){
		int mid = (left+right)/2;
		if(target>LIS[mid])left = mid+1;
		else right = mid;
	}
	return right;
}