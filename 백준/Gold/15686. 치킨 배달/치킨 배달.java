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
	static int board[][] = new int[51][51];
	static boolean visit[] = new boolean[51];
	static boolean visit2[][] = new boolean[51][51];

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

	static List<Pair> c = new LinkedList<>();
	static List<Pair> h = new LinkedList<>();

	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };

	static int ans = Integer.MAX_VALUE;

	static void select(int idx, int cnt) {
		if (cnt == M) {
			calc();
			return;
		}
		for (int i = idx; i < c.size(); i++) {
			visit[i] = true;
			select(i + 1, cnt + 1);
			visit[i] = false;
		}
	}

	static void calc() {
		int tempDist = 0;

		for (Pair home : h) {
			int minDist = Integer.MAX_VALUE;
			for (Pair chick : c) {
				if(visit[chick.cnt]) {
					minDist = Math.min(Math.abs(home.x - chick.x) +  Math.abs(home.y - chick.y),minDist);
				}
			}
			tempDist += minDist;
		}

		ans = Math.min(ans, tempDist);
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		int cnt = 0;

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if (board[i][j] == 1) {
					h.add(new Pair(i, j));
				} else if (board[i][j] == 2) {
					c.add(new Pair(i, j, cnt++));
				}
			}
		}

		select(0, 0);

		System.out.println(ans);
	}
}