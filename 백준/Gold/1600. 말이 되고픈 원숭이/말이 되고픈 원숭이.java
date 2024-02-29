import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
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

	static int K;
	static int W, H;
	static int board[][];
	static int visit[][][][];

	static class Pair {
		int x, y, k, cnt;

		public Pair(int x, int y, int k, int cnt) {
			super();
			this.x = x;
			this.y = y;
			this.k = k;
			this.cnt = cnt;
		}

	}

	static int hx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	static int hy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };

	/*
	 * 1 5 5 0 1 0 0 0 0 1 0 1 0 0 1 0 1 0 0 1 0 1 1 0 0 0 1 0
	 */

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		K = Integer.parseInt(in.readLine());

		st = new StringTokenizer(in.readLine());
		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());

		board = new int[H][W];
		visit = new int[2][H][W][2];

		for (int i = 0; i < H; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < W; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		PriorityQueue<Pair> queue = new PriorityQueue<>(new Comparator<Pair>() {

			@Override
			public int compare(Pair o1, Pair o2) {
				// TODO Auto-generated method stub
				if (o1.cnt == o2.cnt) {
					return -(o1.k - o2.k);
				}
				return o1.cnt - o2.cnt;
			}
		});
		queue.add(new Pair(0, 0, K, 0));

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				visit[0][i][j][0] = Integer.MAX_VALUE;
				visit[0][i][j][1] = -1;
				visit[1][i][j][0] = Integer.MAX_VALUE;
				visit[1][i][j][1] = -1;
			}
		}

		visit[0][0][0][0] = 0;
		visit[0][0][0][1] = K;
		visit[1][0][0][0] = 0;
		visit[1][0][0][1] = K;

		int ans = Integer.MAX_VALUE;

		while (!queue.isEmpty()) {

			Pair p = queue.poll();
			//System.out.println(p.x + " " + p.y + " " + p.k + " " + p.cnt);

			if (p.x == W - 1 && p.y == H - 1) {
				ans = Math.min(ans, p.cnt);
			}

			// 말 원숭이 똑같은 지점을 같은 횟수에 이동할 수 있다면
			// k가 더 큰 쪽으로

			// 인접 방향 이동
			for (int h = 0; h < 4; h++) {
				int tx = p.x + dx[h];
				int ty = p.y + dy[h];
				if (tx >= 0 && tx < W && ty >= 0 && ty < H) {
					// 이동 가능한 공간인 경우
					if (board[ty][tx] == 0) {
						// 기존에 방문한 횟수보다 적거나 || 방문 횟수는 같고 K를 덜 사용한 경우
						if (visit[0][ty][tx][1] < p.k) {
							visit[0][ty][tx][0] = p.cnt;
							visit[0][ty][tx][1] = p.k;
							queue.add(new Pair(tx, ty, p.k, p.cnt + 1));
						}
					}
				}
			}

			// 말 처럼 이동
			if (p.k > 0) {
				for (int h = 0; h < 8; h++) {
					int tx = p.x + hx[h];
					int ty = p.y + hy[h];
					if (tx >= 0 && tx < W && ty >= 0 && ty < H) {
						// 이동 가능한 공간인 경우
						if (board[ty][tx] == 0) {
							// 기존에 방문한 횟수보다 적거나 || 방문 횟수는 같고 K를 덜 사용한 경우
							if (visit[1][ty][tx][1] < p.k - 1) {								visit[1][ty][tx][0] = p.cnt;
								visit[1][ty][tx][0] = p.cnt;
								visit[1][ty][tx][1] = p.k - 1;
								queue.add(new Pair(tx, ty, p.k - 1, p.cnt + 1));
							}
						}
					}
				}
			}
		}
		
		if(ans==Integer.MAX_VALUE) {
			ans=-1;
		}

		System.out.println(ans);

	}
}