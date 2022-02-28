#include <bits/stdc++.h>

using namespace std;

void init();
void Update(int node, int start, int end,int index);
long long cntLess(long long node,int start,int end,int left,int right);

int N;
vector<pair<int,int>>arr;	//정렬을 하기 위한 배열
vector<int>tree;			//세그먼트 트리로 얼마나 Swap 해야하는지 찾기
long long ans = 0;

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
		int num;
		cin >> num;
		arr.push_back(make_pair(num,i));
	}
	
	//배열 정렬
	sort(arr.begin(),arr.end());
	
	//트리 높이 계산
	long long h = (int)ceil(log2(N));
	long long tree_size = (1 << h+1);
	tree.resize(tree_size);
	long long node = 1;
	int start = 0;
	int end = N-1;
	
	for(int i=0;i<N;i++){
		ans += cntLess(node,start,end,arr[i].second,N-1);
		Update(node,start,end,arr[i].second);
	}
	
	cout << ans << "\n";
}

void Update(int node, int start, int end,int index){
	if(start==end){
		tree[node] = 1;
		return ;
	}
	int mid = (start+end)/2;
	if(index<=mid){
		Update(node*2,start,mid,index);
	}
	else{
		Update(node*2+1,mid+1,end,index);
	}
	tree[node] = tree[node*2]+tree[node*2+1];
}

long long cntLess(long long node,int start,int end,int left,int right){
	if(left>end||right<start)return 0;
	if(left<=start&&right>=end)return tree[node];
	int mid = (start+end)/2;
	int leftcnt = cntLess(node*2,start,mid,left,right);
	int rightcnt = cntLess(node*2+1,mid+1,end,left,right);
	return leftcnt + rightcnt;
}
