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
		N = Integer.parseInt(in.readLine());

		for (int i = 0; i < N; i++) {
			String str = in.readLine();
			for (int j = 0; j < N; j++) {
				board[i][j] = str.charAt(j);
			}
		}

		Queue<Pair> queue = new LinkedList<>();

		visit = new boolean[101][101];

		int cnt = 0;
		// 일반인
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					cnt++;
					queue.add(new Pair(i, j));
					visit[i][j] = true;
					while (!queue.isEmpty()) {
						Pair temp = queue.poll();
						for (int k = 0; k < 4; k++) {
							int tx = temp.x + dx[k];
							int ty = temp.y + dy[k];
							if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
								if (board[tx][ty] == board[temp.x][temp.y] && !visit[tx][ty]) {
									visit[tx][ty] = true;
									queue.add(new Pair(tx, ty));
								}
							}
						}
					}
				}
			}
		}

		sb.append(cnt).append(" ");
		cnt = 0;
		visit = new boolean[101][101];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					cnt++;
					queue.add(new Pair(i, j));
					visit[i][j] = true;
					while (!queue.isEmpty()) {
						Pair temp = queue.poll();
						for (int k = 0; k < 4; k++) {
							int tx = temp.x + dx[k];
							int ty = temp.y + dy[k];
							if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
									if (board[temp.x][temp.y] == 'R' || board[temp.x][temp.y] == 'G') {
										if ((board[tx][ty] == 'G' || board[tx][ty] == 'R') && !visit[tx][ty]) {
											visit[tx][ty] = true;
											queue.add(new Pair(tx, ty));
										}
									} else {
										if (board[tx][ty] == 'B'&& !visit[tx][ty]) {
											visit[tx][ty] = true;
											queue.add(new Pair(tx, ty));
										}
									}
							}
						}
					}
				}
			}
		}
		
		sb.append(cnt);
		
		System.out.println(sb);
	}
}