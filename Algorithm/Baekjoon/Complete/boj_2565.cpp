#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int Y[501];		//DP 전깃줄의 오른쪽만 가지고 구할 수 있음
int List[501];	//LIS
void init();
int binary_search(int left,int right,int target);

int main(){
	
	//증가하면 1, 감소하면 -1, 같은 위치에 있으면 0
	init();
	
	
	return 0;
}

//LIS와 감소 수열의 개수를 세서 더 큰 것을 고른다
//안 겹치면 다음 칸에 저장, 겹친다면 +- 비교후 같은 부호면 차이가 더 작은 것을 저장
void init(){
	int M=0;	//최대 개수
	cin >> N;
	
	for(int i=0;i<N;i++){
		int x,y;
		cin >> x >> y;
		Y[x]=y;
		if(x>M)M=x;
	}
	List[1] = Y[1];
	
	int j=0;
	for(int i=1;i<=M;i++){
		//관계가 없다면 건너뜀
		if(Y[i]==0)continue;
		//겹치지 않는다면
		if(Y[i]>List[j]){
			List[j+1] = Y[i];
			j+=1;
		}
		//겹친다면 비교
		else {
			int idx = binary_search(0,j,Y[i]);
			List[idx] = Y[i];
		}
	}
	cout << N -j << "\n";
}

//포인터를 이용하여 비교 혹은 클래스를 이용하여 비교
int binary_search(int left,int right,int target){
	while(left<right){
		//중간 지점 설정
		int mid = (left+right)/2;
		
		//타겟이 중간보다 작다면
		if(target<List[mid])right=mid;
		//타겟이 중간보다 크다면
		else left = mid+1;
	}
	return right;
}
