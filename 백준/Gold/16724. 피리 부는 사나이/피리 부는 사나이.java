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
	static char arr[][] = new char[1000][1000];
	static int set[] = new int[1000001];

	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };

	public static int getParent(int x) {
		if (x == set[x])
			return x;
		else
			return set[x] = getParent(set[x]);
	}

	public static boolean find(int a, int b) {
		a = getParent(a);
		b = getParent(b);

		if (a == b)
			return true;
		else
			return false;
	}

	public static void unionParent(int parent, int child) {
		parent = getParent(parent);
		child = getParent(child);

		set[child] = parent;
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(in.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N * M; i++) {
			set[i] = i;
		}

		for (int i = 0; i < N; i++) {
			String str = in.readLine();
			for (int j = 0; j < M; j++) {
				arr[i][j] = str.charAt(j);
			}
		}

		// SetParent
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int child = i * M + j;
				int parent = -1;

				switch (arr[i][j]) {
				case 'D':
					parent = (i + 1) * M + j;
					if (!find(child, parent)) {
						unionParent(parent, child);
					}
					break;
				case 'U':
					parent = (i - 1) * M + j;
					if (!find(child, parent)) {
						unionParent(parent, child);
					}
					break;
				case 'L':
					parent = i * M + j - 1;
					if (!find(child, parent)) {
						unionParent(parent, child);
					}
					break;
				case 'R':
					parent = i * M + j + 1;
					if (!find(child, parent)) {
						unionParent(parent, child);
					}
					break;
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (set[i * M + j] == i * M + j)
					cnt++;
			}
		}

		System.out.println(cnt);
	}
}