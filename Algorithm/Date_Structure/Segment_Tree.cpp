#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<int>arr(4);		//처음에 입력받아서 생긴 배열
vector<int>tree(8);	//세그먼트 트리가 만들어지는 배열

//세그먼트 트리 초기화
int init(int node,int start,int end);

//세그먼트 트리 갱신
void update(int node,int start,int end, int index, int dif);

//세그먼트 트리 합
int sum(int node, int start, int end, int left, int right);

int main(){
	
	//리프노드의 개수
	int n = 4;
	
	//ceil : 반올림 
	//세그먼트 트리의 크기 (2^h) > N 이어야하므로 h를 구한다 
	int h = (int)ceil(log2(n));
	int tree_size = (1<<(h+1));
	
	//노드의 순서
	//루트 노드를 1이라 할때
	//루트 노드의 왼쪽 노드 : 2 , 오른쪽 노드 : 3으로 표현
	//즉 현재 노드의 번호가 node 일 때 왼쪽 자식 : node*2 , 오른쪽 자식 : node*2+1
	
	//arr에 값 입력
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	int node = 1; //현재 노드의 번호
	int start = 0; //노드의 시작번호
	int end = n-1;	//노드의 끝번호
	
	init(node,start,end);
	
	for(int i=1;i<tree_size;i++){
		cout << tree[i] << " ";
	}
	
	return 0;
}

int init(int node,int start,int end){
	
	//start = end인 곳은 리프노드이므로 해당하는 arr배열 값을 대입하면 된다
	if(start==end)
		return tree[node] = arr[start];
	
	//절반씩 나눠서 보내주는 과정
	int mid = (start + end) / 2;
	
	//절반씩 나눠서 보내준 후에 구간합을 해당 노드에 저장
	return tree[node] = init(node*2,start,mid) + init(node*2+1,mid+1,end);
}

//세그먼트 트리 갱신
void update(int node,int start,int end, int index, int diff){
	
	//index가 올바른 범위안에 없다면 종료
	if(!(start<=index&&index<=end))
		return;
	
	//노드의 변화값을 현재 노드에 갱신
	tree[node] += diff;
	
	//리프노드가 아니라면 자식 노드들을 갱신
	if(start!=end)
	{
		int mid = (start+end)/2;
		update(node*2,start,mid,index,diff);
		update(node*2+1,mid+1,end,index,diff);
	}
}

int sum(int node, int start, int end, int left, int right)
{
	//구간이 겹치지 않는 경우
    if (left > end || right < start)
        return 0;
 	//구간이 완전히 포함되는 경우
    if (left <= start && end <= right)
        return tree[node];
	//구하고자 하는 범위가 구간합 내부에 걸쳐있거나 완전히 포함하는 경우 재탐색
    int mid = (start + end) / 2;
    return sum( node * 2, start, mid, left, right) + sum( node*2+1, mid+1, end, left, right);
}
