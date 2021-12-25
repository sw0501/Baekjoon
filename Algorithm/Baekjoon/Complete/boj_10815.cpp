#include<iostream>
#include<algorithm>

using namespace std;

int N;
int M;
int arr[500001];

void init();
int binary_search(int left,int right, int target);

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	cin >> M;
	
	sort(arr,arr+N);
	
	int target;
	for(int i=0;i<M;i++){
		cin >> target;
		cout << binary_search(0,N,target) << " ";
	}
}

int binary_search(int left, int right, int target){
	int mid;
	while(left<right){
		mid = (left+right)/2;
		if(arr[mid]<target)left = mid+1;
		else right = mid;
	}
	if(arr[right]==target)return 1;
	return 0;
}