//접근 방법이 틀림
//백트래킹으로 풀라는 것은 숫자를 일일히 다 집어넣어봐야하는 것 같음
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Cell {
public:
	int x; //행
	int y; //열
	Cell(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void print() {
		cout << x << " " << y << "\n";
	}
};

int Sudocu[9][9]; 	//스도쿠 입력
vector<Cell>empty; 	//비어있는 셀 저장

int Solve(int n);			//재귀
int inspection(int n); 	//
void init();
void Print();

int main() {

	init();

	return 0;
}

//0이 1개만있는지 확인해서 1개만 있다면 부족한 수 확인
//9칸의 숫자의 총합이 50이 되야함

void init() {
	//스도쿠 입력, 0이라면 empty에 셀 값 저장
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char c;
			cin >> c;
			Sudocu[i][j] = (int)(c - '0');
			if (Sudocu[i][j] == 0)empty.push_back(Cell(i, j));
		}
	}

	//재귀함수를 통해 스도쿠를 채움
	Solve(0);

	Print();
}

//return 값을 이용하여 0일경우 입력했던 값 초기화
//값을 1~9까지 입력한 후 col,row,box로 검사
int Solve(int n) {
	//종료 조건
	if (n == empty.size()) {
		return 0;
	}

	int num = 1;
	int temp = 1; //재귀돌려서 들어갈 수 있는 수인지 확인
	//검사 진행 후 합격하면 ans 재귀하고 ans리턴값을 받아서 temp에 저장
	while (temp) {
		//스도쿠에 숫자 대입
		Sudocu[empty[n].x][empty[n].y] = num;

		int flag = inspection(n);

		//조건을 만족한다면 재귀, 만족하지 않는다면 temp에는 1이 저장되어있으므로 다음 수로 넘어감
		if (flag)
		{
			//cout<<empty[n].x<<" "<<empty[n].y<<"\n";
			//Print();
			//cout<<"\n";
			temp = Solve(n + 1);

		}
		//조건 만족하지 않는다면 다음수로 넘기고 반복
		if (temp)num++;
		//조건 만족하지 않는다면 탈출
		if (num > 9)break;
	}
	//올바른 수를 찾지 못했다면 즉 num>9인 경우 스도쿠 값 초기화
	if (num == 10) {
		Sudocu[empty[n].x][empty[n].y] = 0;
		return 1;
	}
	//아니라면 0 리턴
	return 0;
}

int inspection(int n) {

	int temp = 1;	//중복 확인 변수

	//중복이라면 row,col
	for (int i = 0; i < 9; i++) {
		if (Sudocu[empty[n].x][empty[n].y] == Sudocu[empty[n].x][i] && empty[n].y != i) {
			temp = 0;
			break;
		}
		if (Sudocu[empty[n].x][empty[n].y] == Sudocu[i][empty[n].y] && empty[n].x != i) {
			temp = 0;
			break;
		}
	}

	//중복이라면 box
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Sudocu[(3 * ((empty[n].x) / 3)) + i][(3 * ((empty[n].y) / 3)) + j] == Sudocu[empty[n].x][empty[n].y] && (3 * ((empty[n].x) / 3) + i != empty[n].x && 3 * ((empty[n].y) / 3) + j != empty[n].y)) {
				temp = 0;
				break;
			}
		}
	}

	return temp;

}

// 1개 넣고 

void Print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << Sudocu[i][j];
		}
		cout << "\n";
	}
}
