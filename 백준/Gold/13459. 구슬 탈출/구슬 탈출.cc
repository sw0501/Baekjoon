#include<iostream>
#include<queue>

using namespace std;

struct Marble {
	int rx;
	int ry;
	int bx;
	int by;
	int cnt;
};

char board[10][10] = { 0, };
int N, M, endX, endY;
bool flag = false;
int cnt = 10;

queue<Marble>q;

void up(Marble marble) {
	//위쪽에 위치한 구슬부터 옮기기
	if (marble.bx <= marble.rx) {
		while (1) {
			//벽에 닿을 경우 현재 위치 큐에 저장
			if (board[marble.bx-1][marble.by] == '#') {
				break;
			}
			//파란 공이 먼저 떨어지는 경우는 탈출 불가능하므로
			//큐에 저장하지 않고 빨간 공도 이동하지 않고 함수 종료
			else if (board[marble.bx-1][marble.by] == 'O') {
				return;
			}
			else {
				marble.bx--;
			}
		}
		//파란 공 이동 끝난 후 이동 시작
		while (1) {
			//빨간 공이 벽에 닿거나 파란 공이 위치한 경우
			if (board[marble.rx-1][marble.ry] == '#' || (marble.rx-1 == marble.bx && marble.ry == marble.by)) {
				break;
			}
			//빨간 공만 구멍에 떨어진 경우
			else if (board[marble.rx-1][marble.ry] == 'O') {
				flag = true;
				cnt = (cnt < marble.cnt + 1 ? cnt : marble.cnt + 1);
				break;
			}
			else {
				marble.rx--;
			}
		}
		//이동 끝난 후 큐에 저장
		marble.cnt++;
		if (marble.cnt < 10)q.push(marble);
	}
	else {
		bool flag2 = false;
		//빨간 공 먼저 이동
		while (1) {
			//빨간 공이 벽에 닿은 경우
			if (board[marble.rx-1][marble.ry] == '#') {
				break;
			}
			else if (board[marble.rx-1][marble.ry] == 'O') {
				flag2 = true;
				marble.rx = -1;
				marble.ry = -1;
				break;
			}
			else {
				marble.rx--;
			}
		}
		while (1) {
			//벽에 닿거나 빨간 공에 닿는 경우 현재 위치 큐에 저장
			if (board[marble.bx-1][marble.by] == '#' || (marble.rx == marble.bx-1 && marble.by == marble.ry)) {
				break;
			}
			//파란 공이 떨어지는 경우는 탈출 불가능하므로
			//큐에 저장하지 않고 빨간 공도 이동하지 않고 함수 종료
			else if (board[marble.bx-1][marble.by ] == 'O') {
				flag2 = false;
				return;
			}
			else {
				marble.bx--;
			}
		}
		//이동 끝난 후 큐에 저장
		marble.cnt++;
		//빨간공만
		if (flag2) {
			flag = true;
			cnt = (cnt < marble.cnt ? cnt : marble.cnt);
		}
		if (marble.cnt < 10)q.push(marble);
	}
}

void down(Marble marble) {
	//위쪽에 위치한 구슬부터 옮기기
	if (marble.bx >= marble.rx) {
		while (1) {
			//벽에 닿을 경우 현재 위치 큐에 저장
			if (board[marble.bx + 1][marble.by] == '#') {
				break;
			}
			//파란 공이 먼저 떨어지는 경우는 탈출 불가능하므로
			//큐에 저장하지 않고 빨간 공도 이동하지 않고 함수 종료
			else if (board[marble.bx + 1][marble.by] == 'O') {
				return;
			}
			else {
				marble.bx++;
			}
		}
		//파란 공 이동 끝난 후 이동 시작
		while (1) {
			//빨간 공이 벽에 닿거나 파란 공이 위치한 경우
			if (board[marble.rx + 1][marble.ry] == '#' || (marble.rx + 1 == marble.bx && marble.ry == marble.by)) {
				break;
			}
			//빨간 공만 구멍에 떨어진 경우
			else if (board[marble.rx + 1][marble.ry] == 'O') {
				flag = true;
				cnt = (cnt < marble.cnt + 1 ? cnt : marble.cnt + 1);
				break;
			}
			else {
				marble.rx++;
			}
		}
		//이동 끝난 후 큐에 저장
		marble.cnt++;
		if (marble.cnt < 10)q.push(marble);
	}
	else {
		bool flag2 = false;
		//빨간 공 먼저 이동
		while (1) {
			//빨간 공이 벽에 닿은 경우
			if (board[marble.rx + 1][marble.ry] == '#') {
				break;
			}
			else if (board[marble.rx + 1][marble.ry] == 'O') {
				flag2 = true;
				marble.rx = -1;
				marble.ry = -1;
				break;
			}
			else {
				marble.rx++;
			}
		}
		while (1) {
			//벽에 닿거나 빨간 공에 닿는 경우 현재 위치 큐에 저장
			if (board[marble.bx + 1][marble.by] == '#' || (marble.rx == marble.bx + 1 && marble.by == marble.ry)) {
				break;
			}
			//파란 공이 떨어지는 경우는 탈출 불가능하므로
			//큐에 저장하지 않고 빨간 공도 이동하지 않고 함수 종료
			else if (board[marble.bx + 1][marble.by] == 'O') {
				flag2 = false;
				return;
			}
			else {
				marble.bx++;
			}
		}
		//이동 끝난 후 큐에 저장
		marble.cnt++;
		//빨간공만
		if (flag2) {
			flag = true;
			cnt = (cnt < marble.cnt ? cnt : marble.cnt);
		}
		if (marble.cnt < 10)q.push(marble);
	}
}

void left(Marble marble) {
	//왼쪽에 위치한 구슬부터 옮기기
	if (marble.by <= marble.ry) {
		while (1) {
			//벽에 닿을 경우 현재 위치 큐에 저장
			if (board[marble.bx][marble.by - 1] == '#') {
				break;
			}
			//파란 공이 먼저 떨어지는 경우는 탈출 불가능하므로
			//큐에 저장하지 않고 빨간 공도 이동하지 않고 함수 종료
			else if (board[marble.bx][marble.by - 1] == 'O') {
				return;
			}
			else {
				marble.by--;
			}
		}
		//파란 공 이동 끝난 후 이동 시작
		while (1) {
			//빨간 공이 벽에 닿거나 파란 공이 위치한 경우
			if (board[marble.rx][marble.ry - 1] == '#' || (marble.rx == marble.bx && marble.ry - 1 == marble.by)) {
				break;
			}
			//빨간 공만 구멍에 떨어진 경우
			else if (board[marble.rx][marble.ry - 1] == 'O') {
				flag = true;
				cnt = (cnt < marble.cnt + 1 ? cnt : marble.cnt + 1);
				break;
			}
			else {
				marble.ry--;
			}
		}
		//이동 끝난 후 큐에 저장
		marble.cnt++;
		if (marble.cnt < 10)q.push(marble);
	}
	else {
		bool flag2 = false;
		//빨간 공 먼저 이동
		while (1) {
			//빨간 공이 벽에 닿은 경우
			if (board[marble.rx][marble.ry - 1] == '#') {
				break;
			}
			else if (board[marble.rx][marble.ry - 1] == 'O') {
				flag2 = true;
				marble.rx = -1;
				marble.ry = -1;
				break;
			}
			else {
				marble.ry--;
			}
		}
		while (1) {
			//벽에 닿거나 빨간 공에 닿는 경우 현재 위치 큐에 저장
			if (board[marble.bx][marble.by - 1] == '#' || (marble.rx == marble.bx && marble.by - 1 == marble.ry)) {
				break;
			}
			//파란 공이 떨어지는 경우는 탈출 불가능하므로
			//큐에 저장하지 않고 빨간 공도 이동하지 않고 함수 종료
			else if (board[marble.bx][marble.by - 1] == 'O') {
				return;
			}
			else {
				marble.by--;
			}
		}
		//이동 끝난 후 큐에 저장
		marble.cnt++;
		//빨간공만
		if (flag2) {
			flag = true;
			cnt = (cnt < marble.cnt ? cnt : marble.cnt);
		}
		if (marble.cnt < 10)q.push(marble);
	}
}

void right(Marble marble) {
	//왼쪽에 위치한 구슬부터 옮기기
	if (marble.by >= marble.ry) {
		while (1) {
			//벽에 닿을 경우 현재 위치 큐에 저장
			if (board[marble.bx][marble.by + 1] == '#') {
				break;
			}
			//파란 공이 먼저 떨어지는 경우는 탈출 불가능하므로
			//큐에 저장하지 않고 빨간 공도 이동하지 않고 함수 종료
			else if (board[marble.bx][marble.by + 1] == 'O') {
				return;
			}
			else {
				marble.by++;
			}
		}
		//파란 공 이동 끝난 후 이동 시작
		while (1) {
			//빨간 공이 벽에 닿거나 파란 공이 위치한 경우
			if (board[marble.rx][marble.ry + 1] == '#' || (marble.rx == marble.bx && marble.ry + 1 == marble.by)) {
				break;
			}
			//빨간 공만 구멍에 떨어진 경우
			else if (board[marble.rx][marble.ry + 1] == 'O') {
				flag = true;
				cnt = (cnt < marble.cnt + 1 ? cnt : marble.cnt + 1);
				break;
			}
			else {
				marble.ry++;
			}
		}
		//이동 끝난 후 큐에 저장
		marble.cnt++;
		if (marble.cnt < 10)q.push(marble);
	}
	else {
		bool flag2 = false;
		//빨간 공 먼저 이동
		while (1) {
			//빨간 공이 벽에 닿은 경우
			if (board[marble.rx][marble.ry + 1] == '#') {
				break;
			}
			else if (board[marble.rx][marble.ry + 1] == 'O') {
				flag2 = true;
				marble.rx = -1;
				marble.ry = -1;
				break;
			}
			else {
				marble.ry++;
			}
		}
		while (1) {
			//벽에 닿거나 빨간 공에 닿는 경우 현재 위치 큐에 저장
			if (board[marble.bx][marble.by + 1] == '#' || (marble.rx == marble.bx && marble.by + 1 == marble.ry)) {
				break;
			}
			//파란 공이 떨어지는 경우는 탈출 불가능하므로
			//큐에 저장하지 않고 빨간 공도 이동하지 않고 함수 종료
			else if (board[marble.bx][marble.by + 1] == 'O') {
				flag2 = false;
				return;
			}
			else {
				marble.by++;
			}
		}
		//이동 끝난 후 큐에 저장
		marble.cnt++;
		//빨간공만
		if (flag2) {
			flag = true;
			cnt = (cnt < marble.cnt ? cnt : marble.cnt);
		}
		if (marble.cnt < 10)q.push(marble);
	}
}

void init() {
	cin >> N >> M;

	Marble marble;
	marble.cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				marble.rx = i;
				marble.ry = j;
			}
			else if (board[i][j] == 'B') {
				marble.bx = i;
				marble.by = j;
			}
			else if (board[i][j] == 'O') {
				endX = i;
				endY = j;
			}
		}
	}

	q.push(marble);
}

void BFS() {

	while (!q.empty()) {
		Marble marble = q.front();
		q.pop();

		//왼쪽 기울기
		left(marble);

		//오른쪽 기울기
		right(marble);

		//위로 기울기
		up(marble);

		//아래로 기울기
		down(marble);

		//구멍에 도착했는지 확인
		if (flag) {
			cout << 1 << "\n";
			return;
		}
	}

	cout << 0 << "\n";
	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	BFS();

	return 0;
}