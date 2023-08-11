#include <iostream>

using namespace std;

void init();
void make_Tree(int index);		//트리 만들기
void pre(int index);	//전위 자식 탐색 전 출력
void in(int index);		//중위 왼쪽 자식 탐색을 마친 경우 출력
void post(int index);	//후위 모든 자식 탐색을 마친 경우 출력


int N;
char I[26][2] = {0,};
int L;
int R;
char Tree[67108864];	//높이가 N인 이진트리도 가능하기 때문에 크기를 2^26으로 잡아놨음

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();


	return 0;
}

void init() {
	cin >> N;

	fill(Tree, Tree + 67108864, '.');

	//노드 자식 저장
	for (int i = 0; i < N; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		I[(int)(root - 'A')][0] = left;
		I[(int)(root - 'A')][1] = right;
	}

	Tree[1] = 'A';


	//트리 구성
	make_Tree(1);


	pre(1);
	cout << "\n";
	in(1);
	cout << "\n";
	post(1);

}

//트리 만들기
void make_Tree(int index) {
	if (Tree[index] == '.')return;
	char left = I[(int)(Tree[index] - 'A')][0];
	char right = I[(int)(Tree[index] - 'A')][1];
	Tree[index * 2] = left;
	Tree[index * 2 + 1] = right;
	make_Tree(index * 2);
	make_Tree(index * 2 + 1);
}

//전위 탐색
void pre(int index) {
	//비어있는 트리라면 출력하지 않는다.
	if (Tree[index] == '.')return;

	//자식 탐색 전 출력
	cout << Tree[index];

	pre(2 * index);
	pre(2 * index + 1);
}

//중위 탐색
void in(int index) {
	if (Tree[index] == '.')return;

	in(2 * index);
	//탐색 중간에 출력
	cout << Tree[index];
	in(2 * index + 1);
}

//후위 탐색
void post(int index) {
	if (Tree[index] == '.')return;

	post(2 * index);
	post(2 * index + 1);
	//탐색 마친 후에 출력
	cout << Tree[index];
}
