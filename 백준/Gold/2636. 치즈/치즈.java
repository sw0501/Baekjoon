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
	static int board[][] = new int[101][101];
	static boolean visit[][] = new boolean[101][101];

	static class Pair {
		int x, y, cnt;

		public Pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		public Pair(int x, int y, int cnt) {
			super();
			this.x = x;
			this.y = y;
			this.cnt = cnt;
		}
	}

	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };

	static int ans = Integer.MAX_VALUE;

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		int cnt = 0;
		int t = 0;

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if (board[i][j] == 1)
					cnt++;
			}
		}

		Queue<Pair> queue = new LinkedList<>();

		while (true) {
			int tempCnt = 0;
			t++;

			queue.add(new Pair(0, 0));
			visit = new boolean[101][101];

			// 녹을 치즈 탐색
			while (!queue.isEmpty()) {
				Pair c = queue.poll();

				if (visit[c.x][c.y])
					continue;
				visit[c.x][c.y] = true;

				for (int k = 0; k < 4; k++) {
					int tx = c.x + dx[k];
					int ty = c.y + dy[k];
					if (tx >= 0 && tx < N && ty >= 0 && ty < M) {
						if (board[tx][ty] == 0) {
							queue.add(new Pair(tx, ty));
						} else if (board[tx][ty] == 1) {
							tempCnt++;
							board[tx][ty] = 0;
							visit[tx][ty] = true;
						}
					}
				}
			}

			cnt -= tempCnt;

			if (cnt == 0) {
				System.out.println(t);
				System.out.println(tempCnt);
				break;
			}
		}

	}
}