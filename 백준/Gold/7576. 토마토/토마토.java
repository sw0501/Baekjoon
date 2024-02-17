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

	public static StringBuilder sb = new StringBuilder();
	public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer st;

	static int map[][];
	static boolean visit[][];
	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };

	static class Pair {
		int x, y, cnt;

		public Pair(int x, int y, int cnt) {
			super();
			this.x = x;
			this.y = y;
			this.cnt = cnt;
		}

	}

	public static void main(String[] args) throws IOException {

		st = new StringTokenizer(in.readLine());
		int w = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());

		map = new int[h][w];
		visit = new boolean[h][w];
		int ans = 0;
		boolean flag = true;

		for (int i = 0; i < h; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < w; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 0) {
					flag = false;
				}
			}
		}

		if (!flag) {
			Queue<Pair> queue = new LinkedList<>();

			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (map[i][j] == 1 && !visit[i][j]) {
						queue.add(new Pair(i, j, 0));
						visit[i][j] = true;
					}
				}
			}

			while (!queue.isEmpty()) {
				Pair p = queue.poll();
				ans = Math.max(ans, p.cnt);
				for (int k = 0; k < 4; k++) {
					int tx = p.x + dx[k];
					int ty = p.y + dy[k];

					if (tx >= 0 && tx < h && ty >= 0 && ty < w) {
						if (map[tx][ty] == 0 && !visit[tx][ty]) {
							map[tx][ty] = 1;
							visit[tx][ty] = true;
							queue.add(new Pair(tx, ty, p.cnt + 1));
						}
					}
				}
			}
		}
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if(map[i][j] == 0)ans = -1;
			}
		}

		System.out.println(ans);

	}
}