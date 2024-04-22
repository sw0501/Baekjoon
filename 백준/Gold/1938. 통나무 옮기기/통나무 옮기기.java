import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st = null;

	static char M[][] = new char[50][50];
	// 회전한 경우와 안한 경우 2개로 나눠서 체크
	static boolean check[][][] = new boolean[2][50][50];

	// 이동용 벡터
	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };

	// 확인용 벡터

	static class Point {
		int x, y;
		int isRotate;
		int cnt;

		public Point(int x, int y, int isRotate, int cnt) {
			this.x = x;
			this.y = y;
			this.isRotate = isRotate;
			this.cnt = cnt;
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + ", isRotate=" + isRotate + ", cnt=" + cnt + "]";
		}

	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		int N = Integer.parseInt(br.readLine());

		int cntB = 0;
		int cntE = 0;

		Point start = null;
		Point end = null;

		for (int i = 0; i < N; i++) {
			String str = br.readLine();

			for (int j = 0; j < N; j++) {
				M[i][j] = str.charAt(j);
				if (M[i][j] == 'B') {
					cntB++;
					if (cntB == 2) {
						int isRotate = 0;
						if (i >= 1 && i < N - 1) {
							// 회전 상태인 경우
							if (M[i - 1][j] == 'B') {
								isRotate = 1;
							}
						}

						start = new Point(i, j, isRotate, 0);
					}
				} else if (M[i][j] == 'E') {
					cntE++;
					if (cntE == 2) {
						int isRotate = 0;
						if (i >= 1 && i < N - 1) {
							// 회전 상태인 경우
							if (M[i - 1][j] == 'E') {
								isRotate = 1;
							}
						}

						end = new Point(i, j, isRotate, 0);
					}
				}
			}
		}

		Queue<Point> queue = new LinkedList<>();

		queue.add(start);
		check[start.isRotate][start.x][start.y] = true;

		int answer = 0;
		while (!queue.isEmpty()) {
			Point p = queue.poll();

			if (p.x == end.x && p.y == end.y && p.isRotate == end.isRotate) {
				answer = p.cnt;
				break;
			}

			// 상하좌우 이동
			for (int k = 0; k < 4; k++) {
				int tx = p.x + dx[k];
				int ty = p.y + dy[k];

				// 가로
				if (p.isRotate == 0) {
					if (tx >= 0 && tx < N && ty >= 1 && ty < N - 1 && M[tx][ty] != '1' && M[tx][ty - 1] != '1'
							&& M[tx][ty + 1] != '1' && check[p.isRotate][tx][ty] == false) {
						check[p.isRotate][tx][ty] = true;
						queue.add(new Point(tx, ty, p.isRotate, p.cnt + 1));
					}
				}
				// 세로
				else {
					if (tx >= 1 && tx < N - 1 && ty >= 0 && ty < N && M[tx][ty] != '1' && M[tx + 1][ty] != '1'
							&& M[tx - 1][ty] != '1' && check[p.isRotate][tx][ty] == false) {
						check[p.isRotate][tx][ty] = true;
						queue.add(new Point(tx, ty, p.isRotate, p.cnt + 1));
					}
				}
			}

			// 회전
			if (check[1 - p.isRotate][p.x][p.y] == false) {
				boolean flag = true;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						int tx = p.x + i;
						int ty = p.y + j;
						// 회전할 수 없는 경우
						if (tx < 0 || tx >= N || ty < 0 || ty >= N || M[tx][ty] == '1') {
							flag = false;
						}
					}
				}

				if (flag) {
					check[1 - p.isRotate][p.x][p.y] = true;
					queue.add(new Point(p.x, p.y, 1 - p.isRotate, p.cnt + 1));
				}
			}

		}

		System.out.println(answer);
	}
}