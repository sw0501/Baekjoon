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

import javax.swing.plaf.synth.SynthSplitPaneUI;

public class Main {

	public static StringBuilder sb = new StringBuilder();
	public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer st;

	static List<List<Integer>> arr = new LinkedList<>();
	static boolean visit[] = new boolean[3001];
	static boolean visit2[][] = new boolean[3001][3001];
	static int ans[] = new int[3001];
	static int ck[] = new int[3001];
	static int N;

	// 싸이클 발견할 때 까지 탐색
	public static int check(int node) {
		List<Integer> list = arr.get(node);
		int num = 0;
		for (int i : list) {
			if (!visit2[node][i]) {
				visit2[node][i] = true;
				visit2[i][node] = true;
				ck[i]++;

				// 아직 방문하지 않은 정점이거나 이전 정점인 경우
				if (ck[i] == 1) {
					num = check(i);
					// 사이클 발견한 경우
					if (num != 0)
						break;
				}
				// 싸이클인 경우
				else if (ck[i] == 2) {
					ans[node] = -1;
					return i;
				}
				visit2[node][i] = false;
				visit2[i][node] = false;
				ck[i]--;
			}

		}

		// 사이클에 포함된 경우
		if (num > 0) {
			ans[node] = -1;
			// 사이클 시작점인 경우 사이클이 더이상 포함되지 않았다는 표시 진행
			if (num == node) {
				num = -1;
			}
		}

		return num;
	}

	public static void DFS(int root, int cnt) {
		List<Integer> list = arr.get(root);
		visit[root] = true;
		for (int i : list) {
			// 지선인 경우
			if (!visit[i] && ans[i] == 0) {
				ans[i] = cnt + 1;
				DFS(i, cnt + 1);
			}
		}
		visit[root] = false;
	}

	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(in.readLine());

		for (int i = 0; i <= N; i++) {
			arr.add(new LinkedList<>());
		}

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			arr.get(a).add(b);
			arr.get(b).add(a);
		}

		ck[1] = 1;
		check(1);
		ck[1] = 0;

		// 순환선에 연결된 지선
		for (int i = 1; i <= N; i++) {
			if (ans[i] == -1) {
				DFS(i, 0);
			}
		}

		// 출력
		for (int i = 1; i <= N; i++) {
			if (ans[i] == -1) {
				ans[i] = 0;
			}
			sb.append(ans[i]).append(" ");
		}

		System.out.println(sb);
	}
}