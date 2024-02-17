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

	public static int family[][] = new int[101][101];

	static class Pair {
		int idx, num;

		public Pair(int idx, int num) {
			super();
			this.idx = idx;
			this.num = num;
		}

	}

	public static void main(String[] args) throws IOException {

		int n = Integer.parseInt(in.readLine());

		st = new StringTokenizer(in.readLine());
		int p1 = Integer.parseInt(st.nextToken()), p2 = Integer.parseInt(st.nextToken());

		int m = Integer.parseInt(in.readLine());
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			family[a][b] = 1;
			family[b][a] = 1;
		}

		Queue<Pair> queue = new LinkedList<>();
		for (int i = 1; i <= n; i++) {
			if (family[p1][i] == 1) {
				queue.add(new Pair(i, 1));
				family[p1][i] = 0;
				family[i][p1] = 0;
			}
		}

		while (!queue.isEmpty()) {
			Pair p = queue.poll();
			if (p.idx == p2) {
				System.out.println(p.num);
				return;
			}
			for (int i = 1; i <= n; i++) {
				if (family[p.idx][i] == 1) {
					queue.add(new Pair(i, p.num + 1));
					family[p.idx][i] = 0;
					family[i][p.idx] = 0;
				}
			}
		}

		System.out.println(-1);
	}
}