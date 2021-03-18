#include<iostream>
#include<algorithm>

using namespace std;

class Location{
	public:
	int x;
	int y;
	Location(){
		
	}
	//Location을 이미 생성했으므로 생성자 대신 사용하는 함수
	void set_Location(int x,int y){
		this->x = x;
		this->y = y;
	}
	//연산자 오버로딩을 통해 Location 객체 비교할 때 사용
	bool operator >(Location &location){
		//오름차순으로 정렬하기 위해 클래스1 > 클래스2 는 값1 < 값2 인 상황에서 true 반환
		if(this->y==location.y)return this->x<location.x; 
		return this->y<location.y;
	}
	/*
	//Compare 함수 객체용
	static bool Compare(Location &i,Location &j){
		return i>j;
	}
	//함수오버로딩으로 << Location 하면 출력되게 가능
	void Print(){
		cout << x << " " << y << "\n";
	}
	*/
};

Location *location; //객체 배열
int N; //점의 개수
void init();
void Print();
//함수안에다 static 함수로 넣어서 사용가능
bool Compare(Location i,Location j);

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	
	//입력
	cin >> N;
	location = new Location[N];
	int x;
	int y;
	//Location 객체에 값 대입
	for(int i=0;i<N;i++){
		cin >> x >> y;
		location[i].set_Location(x,y);
	}
	
	//정렬
	sort(location,location+N,Compare);
	
	//출력
	Print();
	
}

//출력 함수
void Print(){
	for(int i=0;i<N;i++){
		cout << location[i].x << " " <<location[i].y << "\n";
	}
}

//sort에 넣어주는 다중 정렬 조건 + 연산자 오버로딩을 통해 자동으로 들어가짐
bool Compare(Location i,Location j){
	return i>j;
}