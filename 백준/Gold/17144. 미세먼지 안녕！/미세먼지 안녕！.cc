#include<iostream>

using namespace std;

int room[50][50] = { 0, };
int R, C, T;

int airx1 = -1, airx2, airy;	//공기 청정기 위치

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void spread();	//미세먼지 확산
void air();		//공기 청정기 작동

int main() {

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];
			if (room[i][j] == -1) {
				if (airx1 == -1) {
					airx1 = i;
					airy = j;
				}
				else {
					airx2 = i;
				}
			}
		}
	}

	for (int t = 0; t < T; t++) {
		spread();
		air();
	}

	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] > 0)cnt += room[i][j];
		}
	}
	cout << cnt << "\n";

	return 0;
}

//미세먼지 확산
void spread() {
	int temp[50][50] = { 0, };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			//미세먼지가 있는 칸이라면
			if (room[i][j] > 0) {

				int cnt = 0;

				for (int k = 0; k < 4; k++) {
					int tx = i + dx[k];
					int ty = j + dy[k];

					//범위 안에 있는 경우
					if (tx >= 0 && ty >= 0 && tx < R && ty < C) {
						//에어컨이 설치된 경우
						if (room[tx][ty] == -1) {
							continue;
						}

						//확산 정보 temp에 저장
						temp[tx][ty] += (int)(room[i][j] / 5);
						cnt++;
					}

					
				}

				room[i][j] -= (int)(room[i][j] / 5) * cnt;
			}
		}
	}

	//확산 정보 room에 적용
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			room[i][j] += temp[i][j];
		}
	}
}

//공기 청정기 작동
void air() {

	//반시계
	int x = airx1;
	int y = airy + 1;

	//공기청정기가 오른쪽 끝 모서리에 있는 경우
	if (airx1 == R - 1) {
		x = airx1 - 1;
		y = airy;
	}

	int temp_dust = 0;	//미세 먼지 임시 저장
	int flag = 0;		//바람 방향성

	//순환할 때 까지
	while (!(x == airx1 && y == airy)) {
		//기존에 있던 먼지 한 칸 이동
		int temp = room[x][y];
		room[x][y] = temp_dust;
		temp_dust = temp;

		//오른쪽 진행
		if (flag==0) {
			//오른쪽 벽에 근접한 경우
			if (y == C - 1) {
				//위로 이동
				x--;
				if (x == 0) {
					//방향 변경
					flag = 1;
				}
			}
			//오른쪽으로 진행 가능한 경우
			else {
				y++;
			}
		}
		//왼쪽 진행
		else {
			//왼쪽 벽에 근접한 경우
			if (y == 0) {
				//아래 이동
				x++;
				if (x == airx1) {
					//방향 변경
					flag = 0;
				}
			}
			//왼쪽 진행 가능한 경우
			else {
				y--;
			}
		}
	}

	//반시계
	x = airx2;
	y = airy + 1;

	//공기청정기가 오른쪽 끝 모서리에 있는 경우
	if (airx2 == R - 1) {
		x = airx2 + 1;
		y = airy;
	}

	temp_dust = 0;	//미세 먼지 임시 저장
	flag = 0;		//바람 방향성

	//시계
	//순환할 때 까지
	while (!(x == airx2 && y == airy)) {
		//기존에 있던 먼지 한 칸 이동
		int temp = room[x][y];
		room[x][y] = temp_dust;
		temp_dust = temp;

		//오른쪽 진행
		if (flag==0) {
			//오른쪽 벽에 근접한 경우
			if (y == C - 1) {
				//아래로 이동
				x++;
				if (x == R - 1) {
					//방향 변경
					flag = 1;
				}
			}
			//오른쪽으로 진행 가능한 경우
			else {
				y++;
			}
		}
		//왼쪽 진행
		else {
			//왼쪽 벽에 근접한 경우
			if (y == 0) {
				//위로 이동
				x--;
				if (x == airx2) {
					//방향 변경
					flag = 0;
				}
			}
			//왼쪽 진행 가능한 경우
			else {
				y--;
			}
		}
	}
}