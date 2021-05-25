#include<iostream>
#include<algorithm>

using namespace std;

int N;					//원소 개수
int m_size = 0;			//중복 제거 배열의 크기

long long S[1000001];	//원본 배열
long long V[1000001];	//정렬한 배열
long long M[1000001];	//중복 제거 배열

void init();

long long binary_search(int left,int right,long long target);

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
		cin >> V[i];
		S[i] = V[i];
	}
	
	sort(V,V+N);
		
	for(int i=0;i<N;i++){
		while(V[i]==V[i+1]){
			i++;
		}
		M[m_size++] = V[i];
	}
	
	
	for(int i=0;i<N;i++){
		cout << binary_search(0,m_size-1,S[i]) << " ";
	}
}

long long binary_search(int left,int right,long long target){
	while(left<right){
		int mid = (left+right)/2;
		if(target>M[mid])
			left = mid+1;
		else
			right = mid;
	}
	return right;
}

