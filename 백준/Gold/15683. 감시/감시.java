import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static StringBuilder sb = new StringBuilder();
	public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer st;

	static int N, M;
	static int arr[][] = new int[8][8];
	static boolean visit[][];

	static class Pair {
		int x, y, k;

		public Pair(int x, int y, int k) {
			super();
			this.x = x;
			this.y = y;
			this.k = k;
		}

	}

	static List<Pair> camera = new ArrayList<>();
	static int rotate[] = new int[8];

	static int cSize = 0;
	static int ans = Integer.MAX_VALUE;

	static void c1(int idx) {
		Pair c = camera.get(idx);
		switch (rotate[idx]) {
		case 0:
			for (int j = c.y + 1; j < M; j++) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			break;
		case 1:
			for (int i = c.x + 1; i < N; i++) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			break;
		case 2:
			for (int j = c.y - 1; j >= 0; j--) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			break;
		case 3:
			for (int i = c.x - 1; i >= 0; i--) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			break;
		}
	}

	static void c2(int idx) {
		Pair c = camera.get(idx);
		switch (rotate[idx] % 2) {
		case 0:
			for (int j = c.y + 1; j < M; j++) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			for (int j = c.y - 1; j >= 0; j--) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			break;
		case 1:
			for (int i = c.x + 1; i < N; i++) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			for (int i = c.x - 1; i >= 0; i--) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			break;
		}
	}

	static void c3(int idx) {
		Pair c = camera.get(idx);
		switch (rotate[idx]) {
		case 0:
			for (int j = c.y + 1; j < M; j++) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			for (int i = c.x - 1; i >= 0; i--) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			break;
		case 1:
			for (int i = c.x + 1; i < N; i++) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			for (int j = c.y + 1; j < M; j++) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			break;
		case 2:
			for (int j = c.y - 1; j >= 0; j--) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			for (int i = c.x + 1; i < N; i++) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			break;
		case 3:
			for (int i = c.x - 1; i >= 0; i--) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			for (int j = c.y - 1; j >= 0; j--) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			break;
		}
	}

	static void c4(int idx) {
		Pair c = camera.get(idx);
		switch (rotate[idx]) {
		case 0:
			for (int j = c.y + 1; j < M; j++) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			for (int j = c.y - 1; j >= 0; j--) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			for (int i = c.x - 1; i >= 0; i--) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			break;
		case 1:
			for (int i = c.x - 1; i >= 0; i--) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			for (int i = c.x + 1; i < N; i++) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			for (int j = c.y + 1; j < M; j++) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			break;
		case 2:
			for (int j = c.y - 1; j >= 0; j--) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			for (int j = c.y + 1; j < M; j++) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			for (int i = c.x + 1; i < N; i++) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			break;
		case 3:
			for (int i = c.x - 1; i >= 0; i--) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			for (int j = c.y - 1; j >= 0; j--) {
				if (arr[c.x][j] != 6) {
					visit[c.x][j] = true;
				} else {
					break;
				}
			}
			for (int i = c.x + 1; i < N; i++) {
				if (arr[i][c.y] != 6) {
					visit[i][c.y] = true;
				} else {
					break;
				}
			}
			break;
		}
	}

	static void c5(int idx) {
		Pair c = camera.get(idx);
		for (int i = c.x - 1; i >= 0; i--) {
			if (arr[i][c.y] != 6) {
				visit[i][c.y] = true;
			} else {
				break;
			}
		}
		for (int j = c.y - 1; j >= 0; j--) {
			if (arr[c.x][j] != 6) {
				visit[c.x][j] = true;
			} else {
				break;
			}
		}
		for (int i = c.x + 1; i < N; i++) {
			if (arr[i][c.y] != 6) {
				visit[i][c.y] = true;
			} else {
				break;
			}
		}
		for (int j = c.y + 1; j < M; j++) {
			if (arr[c.x][j] != 6) {
				visit[c.x][j] = true;
			} else {
				break;
			}
		}
	}

	static int check() {
		visit = new boolean[8][8];
		// 모든 감시 카메라 탐색
		for (int i = 0; i < cSize; i++) {
			if (camera.get(i).k == 1) {
				c1(i);
			} else if (camera.get(i).k == 2) {
				c2(i);
			} else if (camera.get(i).k == 3) {
				c3(i);
			} else if (camera.get(i).k == 4) {
				c4(i);
			} else if (camera.get(i).k == 5) {
				c5(i);
			}
		}

		int cnt = N * M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if ((arr[i][j] == 0 && visit[i][j]) || arr[i][j] > 0)
					cnt--;
			}
		}

		return cnt;
	}

	static void select(int cnt, int idx) {
		if (cnt == cSize) {
			int num = check();
			ans = Math.min(ans, num);
		}
		for (int i = idx; i < cSize; i++) {
			// 회전
			for (int k = 0; k < 4; k++) {
				rotate[i] = k;
				select(cnt + 1, i + 1);
			}
		}
	}

	public static void main(String[] args) throws IOException {

		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] > 0 && arr[i][j] < 6) {
					camera.add(new Pair(i, j, arr[i][j]));
					cSize++;
				}
			}
		}

		select(0, 0);

		System.out.println(ans);
	}
}