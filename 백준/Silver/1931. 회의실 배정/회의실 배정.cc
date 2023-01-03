#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Meeting{
	public:
	int start;	//시작시간
	int end;	//종료시간
	void set_Meet(int start,int end){
		this->start=start;
		this->end=end;
	}
	//종료시간을 기준으로 오름차순으로 정렬
	bool operator >(Meeting &m){
		if(m.end==end)return m.start>start;
		return m.end>end;
	}
	void print(){
		cout << start << " " << end << "\n";
	}
};

int M = 1;		//회의 개수 카운트
int s = 0;		//시작 시간
int e = 0;		//종료 시간
int N;			//회의실 개수
Meeting *meet;	//회의 클래스

void init();
bool compare(Meeting &m1, Meeting &m2);
void search(int n);

int main(){
	
	init();
	
	return 0;
}

//종료시간 기준으로 정렬하여 사용하는 것이 그리디요소 O(n)만 소모
void init(){
	cin >> N;
	meet = new Meeting[N];
	
	for(int i=0;i<N;i++){
		cin >> meet[i].start >> meet[i].end;
	}
	
	//시작시간과 종료시간을 기준으로 정렬
	sort(meet,meet+N,compare);
	
	s = meet[0].start;
	e = meet[0].end;
	
	for(int i=1;i<N;i++){
		//시작시간과 종료시간이 같다면 (이 경우엔 다음 최우선 순위이기 때문에 무조건 사용)
		if(meet[i].start==meet[i].end){
			M++;
		}
		//종료시간이후에 시작하는 회의는 카운트
		else if(meet[i].start>e||meet[i].start==e){
			M++;
			s=meet[i].start;
			e=meet[i].end;
		}
	}
	
	delete []meet;
	
	cout << M << "\n";
	
}

bool compare(Meeting &m1, Meeting &m2){
	return m1>m2;	
}