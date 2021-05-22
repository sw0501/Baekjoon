#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

vector<int>tree(1);	//세그먼트 트리 배열

//세그먼트 트리 초기화
int init(int node,int start,int end);
//세그먼트 트리 갱신
void update(int node,int start,int end,int index,int diff);
//세그먼트 트리 구간합
int sum(int node,int start,int end,int left,int right);
//요세푸스 순열 인덱스 검색
int search(int node,int target,int start,int end);

int main(){
	
	int N;	//리프노드의 개수
	int K;	//목표 인덱스 순번
	cin >> N >> K;
	getchar();
	int node = 1;	//현재 노드의 번호
	int start = 1;	//노드의 시작 번호
	int end = N;	//노드의 끝 번호
	
	//세그먼트 트리 사이즈 구하기
	int h = (int)ceil(log2(N));
	int tree_size = (1<<(h+1));
	
	//배열 크기 변경
	tree.resize(tree_size);

	//세그먼트 트리 초기화
	init(node,start,end);
	
	int last_index = 0;
	
	cout << "<";
	//트리의 총 구간합이 0이 될 때까지
	while(tree[1]){
		int T = K;	//해당하는 인덱스까지의 세그먼트 트리의 누적인덱스
		
		//뽑은 순열이 존재하는 경우
		if(last_index)
			//1부터 현재지점 인덱스까지의 누적합 S + 이후에 계산할 부분 누적합 K를 합한후 총 노드의 나머지를 구하면 해당하는 누적합을 가진 인덱스가 목표 인덱스가 된다.
			T = (sum(node,start,end,start,last_index)+K)%(tree[1]);

		//T==0인 경우는 세그먼트 트리의 1을 가진 마지막 리프노드가 목표 인덱스가 된다.
		if(T==0)
			T = tree[1];
		
		//result 배열에다 찾은 인덱스 저장
		last_index = search(node,T,start,end);
		
		//찾은 인덱스를 0으로 만들고 세그먼트 트리 갱신
		update(node,start,end,last_index,-1);
		
		cout << last_index;
		if(tree[1])cout<<", ";
		else cout<<">";
	}
	
	return 0;
}

int init(int node,int start,int end){
	//리프 노드인 경우 arr 배열의 값 저장
	if(start==end)
		return tree[node] = 1;
	
	int mid = (start+end)/2;
	//자식노드 초기화한 후 구간합 저장
	return tree[node] = init(node*2,start,mid) + init(node*2+1,mid+1,end);
}

void update(int node,int start,int end,int index,int diff){
	//변경된 값을 포함하지 않는 범위인 경우
	if(!(start<=index&&index<=end))
		return;
	
	//차이만큼 현재 노드의 값 갱신해줌
	tree[node] += diff;
	
	//리프노드가 아니라면 자식노드 계속 탐색하며 갱신
	if(start!=end){
		int mid = (start+end)/2;
		update(node*2,start,mid,index,diff);
		update(node*2+1,mid+1,end,index,diff);
	}
}

int sum(int node,int start,int end,int left,int right){
	//포함되지 않는 구간일 경우
	if(left>end||right<start)
		return 0;
	
	//완전히 포함되는 구간인 경우
	if(left<=start&&end<=right)
		return tree[node];
	
	//걸쳐있거나 완전히 포함하는 경우
	int mid = (start+end)/2;
	return sum(node*2,start,mid,left,right) + sum(node*2+1,mid+1,end,left,right);
}


//해당하는 누적합을 가진 인덱스를 찾아서 반환한다.
int search(int node,int target,int start,int end){
	//목표 인덱스를 찾았다면 반환
	if(start==end)
		return start;
	
	int mid = (start+end)/2;
	
	//목표 누적합의 크기에 따라 탐색 노드 결정
	//작을 경우 왼쪽 노드 탐색
	if(target<=tree[node*2])
		return search(node*2,target,start,mid);
	
	//클 경우 해당하는 인덱스까지의 누적합을 제외한 후의 오른쪽 노드 탐색
	else return search(node*2+1,target-tree[node*2],mid+1,end);
}







