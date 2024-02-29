import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, M;
	static int map[][];
	static int ans = 0;

	static class Pair {
		int x, y;

		public Pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	static void select(int cnt) {
		if (cnt == 3) {
			boolean visit[][] = new boolean[N][M];

			Queue<Pair> queue = new LinkedList<>();

			int dx[] = { 1, -1, 0, 0 };
			int dy[] = { 0, 0, 1, -1 };

			int temp[][] = new int[N][M];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					temp[i][j] = map[i][j];
					if (temp[i][j] == 2) {
						visit[i][j] = true;
						queue.add(new Pair(i, j));
					}
				}
			}

			while (!queue.isEmpty()) {
				Pair p = queue.poll();

				for (int k = 0; k < 4; k++) {
					int tx = p.x + dx[k];
					int ty = p.y + dy[k];

					if (tx >= 0 && tx < N && ty >= 0 && ty < M) {
						if (!visit[tx][ty] && temp[tx][ty] == 0) {
							visit[tx][ty] = true;
							temp[tx][ty] = 2;
							queue.add(new Pair(tx, ty));
						}
					}
				}
			}

			int tempCnt = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (temp[i][j] == 0)
						tempCnt++;
				}
			}

			ans = Math.max(ans, tempCnt);

			return;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
					select(cnt + 1);
					map[i][j] = 0;
				}
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		map = new int[N][M];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		select(0);

		System.out.println(ans);
	}
}