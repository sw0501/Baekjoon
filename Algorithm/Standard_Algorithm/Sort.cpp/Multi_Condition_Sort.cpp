#include<iostream>
#include<algorithm>

using namespace std;

class Location{
	public:
	int x;
	int y;
	Location(){
		
	}
	void set_Location(int x,int y){
		this->x = x;
		this->y = y;
	}
	bool operator >(Location &location){
		if(this->x==location.x)return this->y<location.y;
		return this->x<location.x;
	}
};

Location *location; //객체 배열
int N; //점의 개수
void init();
void Print();
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
	
	for(int i=0;i<N;i++){
		cin >> x >> y;
		location[i].set_Location(x,y);
	}
	
	//정렬
	sort(location,location+N,Compare);
	
	//출력
	Print();
	
}

void Print(){
	for(int i=0;i<N;i++){
		cout << location[i].x << " " <<location[i].y << "\n";
	}
}

bool Compare(Location i,Location j){
	return i>j;
}