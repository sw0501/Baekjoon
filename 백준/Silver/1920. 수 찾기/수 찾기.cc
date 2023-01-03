#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int arr[100001];
int N;
int M;

void binary_search(int left,int right,int target);

int main(){
	
	cin >> N;
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+N);
	cin >> M;
	int x;
	for(int i=0;i<M;i++){
		scanf("%d",&x);
		binary_search(0,N-1,x);
	}
}

void binary_search(int left,int right,int target){
	while(left<right){
		int mid = (left+right)/2;
		if(target>arr[mid])left=mid+1;
		else right = mid;
	}
	if(target==arr[right])printf("1\n");
	else printf("0\n");
}