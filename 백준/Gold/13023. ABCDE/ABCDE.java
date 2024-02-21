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

	static List<List<Integer>> p = new ArrayList<>();
	static boolean visit[] = new boolean[2000];

	static boolean flag = false;

	static void DFS(int idx, int cnt) {
		if (cnt == 5) {
			flag = true;
			return;
		}
		visit[idx] = true;
		for (int i : p.get(idx)) {
			if (!visit[i]) {
				DFS(i, cnt + 1);
			}
		}
		visit[idx] = false;
	}

	public static void main(String[] args) throws IOException {

		st = new StringTokenizer(in.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N; i++) {
			p.add(new ArrayList<>());
		}

		for (int i = 0; i < M; i++) {
			int a, b;
			st = new StringTokenizer(in.readLine());

			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			p.get(a).add(b);
			p.get(b).add(a);
		}

		for (int i = 0; i < N; i++) {
			DFS(i, 1);
			if (flag) {
				System.out.println(1);
				return;
			}
		}

		System.out.println(0);
	}
}