#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

int N,M;
vector<int>arr;
void init();
int binary_search(int left,int right,int target);

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	
	int m = -10000001;
	
	for(int i=0;i<N;i++){
		int n;
		scanf("%d",&n);
		if(m<n)m=n;
		arr.push_back(n);
	}
	
	sort(arr.begin(),arr.end());
	
	cin >> M;
	int x;
	for(int i=0;i<M;i++){
		scanf("%d",&x);
		//x를 찾을 때 x+1을 이분검색하면 마지막 x의 인덱스를 가리킨다. 그리고 x를 검색하면 첫 x의 인덱스를 가리킨다.
		//가장 큰 수를 찾아야 할 경우에는 자신보다 큰 수를 검색해도 자신의 마지막 인덱스를 가리키기 때문에 1을 추가해준다.
		int idx = binary_search(0,N-1,x+1) - binary_search(0,N-1,x);
		if(x==m)idx++;
		cout << idx << " ";
	}
}

int binary_search(int left,int right,int target){
	while(left<right){
		int mid = (left+right)/2;
		if(target>arr[mid])left=mid+1;
		else right = mid;
	}
	return right;
}
