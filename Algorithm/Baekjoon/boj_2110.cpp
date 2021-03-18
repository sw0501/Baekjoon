#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int C;
vector<int>X;
int Arr[200001];
int MIN=1000000000;

int binary_search(int left,int right,int target);
int abs(int A,int B);
void init();

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> N >> C;
	int M=0;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		M=max(M,num);
		X.push_back(num);
	}
	
	//벡터로 X를 받은 다음에 정렬을 하여 이분탐색을 할 수 있도록 만들어줌
	sort(X.begin(),X.end());
	
	//초기화
	for(int i=0;i<=M;i++){
		Arr[i] = i;
	}
	
	//가장자리에 1개씩 공유기를 미리 설치한 후에 이분탐색 진행
	int left = 0;		//왼쪽 끝 인덱스
	int right = N-1;	//오른쪽 끝 인덱스
	MIN = X[right]- X[left];
	
	int c = 2;
	
	while(c<C){
		//공유기 사이의 중간값 저장
		int mid = (X[left]+X[right])/2;
		int idx = binary_search(left+1,right-1,mid);
		
		//0 1 2 4 5 -> 3은 4의 위치에 들어감
		//0 1 2 3 4 5  -> 3은 3의 위치에 들어감
		//target은 무조건 자기보다 큰 수가 있는 위치로 탐색되므로 idx-1, idx 비교하여 절대값이 작은 수를 고르면 됨
		
		//설치할 공유기가 1개 남았다면
		if(C-c==1){
			idx = (X[idx]-mid<mid-X[idx-1]?idx:idx-1);
			MIN = min(X[idx]-X[left],X[right]-X[idx]);
			c++;
		}
		//2개 이상 남았다면 찾은 중앙값을 기준으로 다시 이분정렬을 한 후 i, i+1 ,i-1 과의 거리 비교
		else {
			mid = (X[left]+X[idx-1])/2;
			int idx1 = binary_search(left+1,idx-1,mid);
			//비교하여 들어갈 인덱스 저장
			idx1 = (X[idx1]-mid<mid-X[idx1-1]?idx1:idx1-1);
			MIN = min(MIN,X[idx1]-X[left]);
			left = idx1;
			c++;
			
			mid = (X[idx]+X[right])/2;
			int idx2 = binary_search(idx,right-1,mid);
			//비교하여 들어갈 인덱스 저장
			idx2 = (X[idx2]-mid<mid-X[idx2-1]?idx2:idx2-1);
			MIN = min(MIN,X[right]-X[idx2]);
			c++;
		}
	}
	
	cout << MIN << "\n";
}

int binary_search(int left,int right,int target){
	while(left<right){
		int mid = (left+right)/2;
		if(target<X[mid]){
			right = mid;
		}
		else left = mid+1;
	}
	return right;
}

int abs(int A,int B){
	if(A>B)return A-B;
	return B-A;
}

