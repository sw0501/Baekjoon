//���� ����� Ʋ��
//��Ʈ��ŷ���� Ǯ��� ���� ���ڸ� ������ �� ����־�����ϴ� �� ����
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Cell {
public:
	int x; //��
	int y; //��
	Cell(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void print() {
		cout << x << " " << y << "\n";
	}
};

int Sudocu[9][9]; 	//������ �Է�
vector<Cell>empty; 	//����ִ� �� ����

int Solve(int n);			//���
int inspection(int n); 	//
void init();
void Print();

int main() {

	init();

	return 0;
}

//0�� 1�����ִ��� Ȯ���ؼ� 1���� �ִٸ� ������ �� Ȯ��
//9ĭ�� ������ ������ 50�� �Ǿ���

void init() {
	//������ �Է�, 0�̶�� empty�� �� �� ����
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char c;
			cin >> c;
			Sudocu[i][j] = (int)(c - '0');
			if (Sudocu[i][j] == 0)empty.push_back(Cell(i, j));
		}
	}

	//����Լ��� ���� ������ ä��
	Solve(0);

	Print();
}

//return ���� �̿��Ͽ� 0�ϰ�� �Է��ߴ� �� �ʱ�ȭ
//���� 1~9���� �Է��� �� col,row,box�� �˻�
int Solve(int n) {
	//���� ����
	if (n == empty.size()) {
		return 0;
	}

	int num = 1;
	int temp = 1; //��͵����� �� �� �ִ� ������ Ȯ��
	//�˻� ���� �� �հ��ϸ� ans ����ϰ� ans���ϰ��� �޾Ƽ� temp�� ����
	while (temp) {
		//������ ���� ����
		Sudocu[empty[n].x][empty[n].y] = num;

		int flag = inspection(n);

		//������ �����Ѵٸ� ���, �������� �ʴ´ٸ� temp���� 1�� ����Ǿ������Ƿ� ���� ���� �Ѿ
		if (flag)
		{
			//cout<<empty[n].x<<" "<<empty[n].y<<"\n";
			//Print();
			//cout<<"\n";
			temp = Solve(n + 1);

		}
		//���� �������� �ʴ´ٸ� �������� �ѱ�� �ݺ�
		if (temp)num++;
		//���� �������� �ʴ´ٸ� Ż��
		if (num > 9)break;
	}
	//�ùٸ� ���� ã�� ���ߴٸ� �� num>9�� ��� ������ �� �ʱ�ȭ
	if (num == 10) {
		Sudocu[empty[n].x][empty[n].y] = 0;
		return 1;
	}
	//�ƴ϶�� 0 ����
	return 0;
}

int inspection(int n) {

	int temp = 1;	//�ߺ� Ȯ�� ����

	//�ߺ��̶�� row,col
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

	//�ߺ��̶�� box
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

// 1�� �ְ� 

void Print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << Sudocu[i][j];
		}
		cout << "\n";
	}
}
