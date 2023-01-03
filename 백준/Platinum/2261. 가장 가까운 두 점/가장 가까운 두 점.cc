#include <bits/stdc++.h>

using namespace std;

void init();
int BinarySearch(int low,int high);
int Distance(int low,int high);

int N;
const int MAX = 2000000000;
vector<pair<int,int>>v;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	v = vector<pair<int,int>>(N);
	
	for(int i=0;i<N;i++){
		cin >> v[i].first >> v[i].second;
	}
	
	//x값에 대하여 정렬
	sort(v.begin(),v.end());
	
	int answer = BinarySearch(0,N-1);
	
	cout << answer << "\n";
}

//이분탐색으로 low +1 = high 일때까지 분할 정복 후에 비교
int BinarySearch(int low,int high){
	//같은 경우는 포함하지 않으므로 최대거리로 리턴
	if(low == high){
		return MAX;
	}
	//이분탐색으로 발견한 경우
	if(low+1 >= high){
		return Distance(low,high);
	}
	
	//이분탐색으로 low,high 줄여나가면서 비교
	int disMin = Distance(low,high);
	int tempDis = 0, mid = (low+high)/2;
	
	//왼쪽 영역
	if((tempDis = BinarySearch(low,mid))<disMin){
		disMin = tempDis;
	}
	//오른쪽 영역
	if((tempDis = BinarySearch(mid+1,high))<disMin){
		disMin = tempDis;
	}
	
	vector<pair<int,int>>Y;
	int lineX = v[mid].first;
	//왼쪽 기준 x차이가 최소거리보다 작은 경우 탐색
	for(int i=mid;i>=low;i--){
		int x = v[i].first;
		int dist = lineX - x;
		
		//x기준으로 정렬됐기 때문에 거리의 최솟값보다 크다면 이후의 값들도 전부 크다 
		if(disMin <= dist*dist)break;
		//x기준을 만족한 점을 발견한 경우 y기준으로 정렬하기 위해 y,x 페어로 벡터에 저장
		Y.push_back(make_pair(v[i].second,x));
	}
	//오른쪽 기준 x차이가 최소거리보다 작은 경우 탐색
	for(int i=mid+1;i<=high;i++){
		int x = v[i].first;
		int dist = lineX - x;
		
		//x기준으로 정렬됐기 때문에 거리의 최솟값보다 크다면 이후의 값들도 전부 크다 
		if(disMin <= dist*dist)break;
		//x기준을 만족한 점을 발견한 경우 y기준으로 정렬하기 위해 y,x 페어로 벡터에 저장
		Y.push_back(make_pair(v[i].second,x));
	}
	
	//x거리의 차이가 disMin보다 적은 점을 발견하지 못했다면 그동안 찾은 최솟값 반환
	if(Y.size()==0)return disMin;
	
	sort(Y.begin(),Y.end());
	
	//y거리의 차이가 disMin보다 작고 x거리도 작은 지 비교
	for(int i=0;i<Y.size();i++){
		int ix = Y[i].second;
		int iy = Y[i].first;
		for(int j=i+1;j<Y.size();j++){
			int jx = Y[j].second;
			int jy = Y[j].first;
			int distX = (ix-jx)*(ix-jx);
			int distY = (iy-jy)*(iy-jy);
			//y거리가 최소 거리보다 크다면 이후 y들은 모두 크기 때문에 종료
			if(disMin<=distY){
				break;
			}
			//x거리가 최소 거리보다 큰 경우엔 continue
			if(disMin<=distX){
				continue;
			}
			//기준을 만족하는 경우
			int dist = distX+distY;
			
			if(dist<disMin){
				disMin = dist;
			}
		}
	}
	
	return disMin;
}

int Distance(int low,int high){
	int lx = v[low].first;
	int ly = v[low].second;
	int hx = v[high].first;
	int hy = v[high].second;
	
	return (hx-lx)*(hx-lx)+(hy-ly)*(hy-ly);
}