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

	static int N;
	static int area[][] = new int[11][11];
	static int person[] = new int[11];

	static boolean t[] = new boolean[11];
	static boolean visit[];
	static int ans = Integer.MAX_VALUE;

	static void dfs(int idx) {
		for (int i = 1; i <= N; i++) {
			// 연결되어 있음, 같은 지역구, 방문 안함
			if (area[idx][i] == 1 && t[idx] == t[i] && !visit[i]) {
				visit[i] = true;
				dfs(i);
			}
		}
	}

	static void check() {
		int c = 0;

		visit = new boolean[11];

		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				visit[i] = true;
				dfs(i);
				c++;
			}
		}

		if (c != 2)
			return;

		boolean flag = true;
		int cnt1 = 0, cnt0 = 0;
		for (int i = 1; i <= N; i++) {
			if (!visit[i])
				flag = false;
			if (t[i] == true) {
				cnt1 += person[i];
			} else {
				cnt0 += person[i];
			}
		}
		if (flag) {
			ans = Math.min(ans, Math.abs(cnt1 - cnt0));
		}
	}

	static void select(int idx) {
		for (int i = idx; i <= N; i++) {
			t[idx] = true;
			check();
			select(i + 1);
			t[idx] = false;
		}
	}

	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(in.readLine());

		st = new StringTokenizer(in.readLine());

		for (int i = 1; i <= N; i++) {
			person[i] = Integer.parseInt(st.nextToken());
		}

		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(in.readLine());
			int M = Integer.parseInt(st.nextToken());
			for (int j = 0; j < M; j++) {
				int num = Integer.parseInt(st.nextToken());
				area[i][num] = 1;
			}
		}

		select(1);

		if (ans == Integer.MAX_VALUE)
			ans = -1;
		System.out.println(ans);
	}
}