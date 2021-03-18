//주의사항 ※ 탐색할 배열이 오름차순 혹은 내림차순으로 정렬이 되어있어야 사용가능
#include<iostream>

using namespace std;

int list[1001];	//탐색할 배열

int binary_search(int left,int right,int target);
void init();

int main(){
	
	init();
	
	return 0;
}

void init(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> list[i];
	}
	int j = N-1;	//배열의 끝
	while(1){
		int num;
		int idx;
		cin >> num;
		if(num>list[j]){
			list[++j]=num;
			idx = j;	
		}
		else idx = binary_search(0,j,num)+1;
		cout << idx << "\n";
	}
}

int binary_search(int left,int right,int target){
	
	//위치를 찾을때까지 반복
	while(left<right){
		//중간 위치 설정
		int mid = (left+right)/2;
		
		//target>mid
		if(target>list[mid])left = mid+1;
		//target<mid
		else right = mid;
	}
	//찾은 인덱스 반환
	return right;
}
