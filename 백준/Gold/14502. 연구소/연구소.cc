#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int a, b;
int arr[8][8];
vector<pair<int, int>> virus;
int MAX;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void search() {
	
	int cnt = a * b;
	int wall = 0;

	//바이러스 계산용 테이블
	int temp[8][8] = { 0, };

	//복사
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			//구역 복사
			temp[i][j] = arr[i][j];

			//벽 개수
			if (arr[i][j] == 1) {
				wall++;
			}
		}
	}

	//벽 개수만큼 안전구역 제거
	cnt -= wall;

	//BFS용 큐
	queue<pair<int, int>>BFS;
	for (int n = 0; n < virus.size(); n++) {
		//virus 시작 지점 큐에 삽입
		BFS.push(virus[n]);

		
		//위험구역 개수
		cnt--;
		
	}

	//BFS 탐색 시작
	while (!BFS.empty()) {
		int x = BFS.front().first;
		int y = BFS.front().second;

		BFS.pop();

		//상하좌우 탐색
		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			//이동 가능한 경우
			if (tx >= 0 && ty >= 0 && tx < a && ty < b) {
				//탐색 가능한 경우
				if (temp[tx][ty] == 0) {
					temp[tx][ty] = 2;
					cnt--;
					BFS.push({ tx,ty });
				}
			}
		}
	}
	
	int tem = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (temp[i][j] == 0)tem++;
		}
	}

	MAX = (MAX < cnt ? cnt : MAX);
}

void select(int x,int y, int N) {

	//전체 방 탐색
	for (int i = x; i < a; i++) {
		//첫 번째 반복일 경우 y 아닐 경우 0열부터 탐색
		for (int j = (i == x ? y : 0); j < b; j++) {
			//빈 칸인 경우
			if (arr[i][j] == 0) {
				//벽 세우기
				arr[i][j] = 1;

				//마지막 벽이라면
				if (N == 3) {
					search();
				}
				//마지막 벽이 아니라면
				else {
					select(i, j, N + 1);
				}
				
				//벽 다시 돌려놓기
				arr[i][j] = 0;
			}
		}
	}
}

int main() {

	cin >> a >> b;

	MAX = 0;

	//방 구조 입력
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> arr[i][j];
			//바이러스인 경우 위치 저장
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	//벽 선택
	select(0, 0, 1);

	//최대 안전구역 출력
	cout << MAX << "\n";

	return 0;
}