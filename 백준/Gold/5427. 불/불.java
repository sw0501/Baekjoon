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

	static int T;
	static char b[][];
	static boolean visit[][];

	static class Pair {
		int x, y, cnt;

		public Pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
			cnt = 0;
		}

		public Pair(int x, int y, int cnt) {
			super();
			this.x = x;
			this.y = y;
			this.cnt = cnt;
		}
	}

	static int[] dx = { 1, -1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };

	public static void main(String[] args) throws IOException {

		T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(in.readLine());
			int w = Integer.parseInt(st.nextToken());
			int h = Integer.parseInt(st.nextToken());

			b = new char[h][w];
			visit = new boolean[h][w];

			Queue<Pair> fire = new LinkedList<>();
			Queue<Pair> temp = new LinkedList<>();
			Queue<Pair> person = new LinkedList<>();

			// 불과 사람 위치 저장
			for (int i = 0; i < h; i++) {
				String str = in.readLine();
				for (int j = 0; j < w; j++) {
					b[i][j] = str.charAt(j);
					if (b[i][j] == '@') {
						b[i][j] = '.';
						visit[i][j] = true;
						person.add(new Pair(i, j));
					} else if (b[i][j] == '*') {
						fire.add(new Pair(i, j));
					}
				}
			}

			boolean flag = true;
			while (!person.isEmpty()) {
				// 불 번짐
				while (!fire.isEmpty()) {
					Pair f = fire.poll();
					for (int k = 0; k < 4; k++) {
						int tx = f.x + dx[k];
						int ty = f.y + dy[k];

						// 범위 내에 있는 경우
						if (tx >= 0 && tx < h && ty >= 0 && ty < w) {
							// 빈 공간인 경우
							if (b[tx][ty] == '.') {
								b[tx][ty] = '*';
								temp.add(new Pair(tx, ty));
							}
						}
					}
				}
				// 불 저장
				while (!temp.isEmpty()) {
					fire.add(temp.poll());
				}

				// 사람 이동
				while (!person.isEmpty()) {
					Pair p = person.poll();
					for (int k = 0; k < 4; k++) {
						int tx = p.x + dx[k];
						int ty = p.y + dy[k];

						// 범위 내에 있는 경우
						if (tx >= 0 && tx < h && ty >= 0 && ty < w) {
							// 빈 공간인 경우
							if (b[tx][ty] == '.' && !visit[tx][ty]) {
								visit[tx][ty] = true;
								temp.add(new Pair(tx, ty, p.cnt + 1));
							}
						}
						// 범위 밖으로 탈출한 경우
						else {
							flag = false;
							sb.append(p.cnt + 1).append("\n");
							while (!person.isEmpty()) {
								person.poll();
							}
							while (!temp.isEmpty()) {
								temp.poll();
							}
							break;
						}
					}
				}
				// 사람 저장
				while (!temp.isEmpty()) {
					person.add(temp.poll());
				}
			}
			if (flag) {
				sb.append("IMPOSSIBLE\n");
			}
		}

		System.out.println(sb);
	}
}