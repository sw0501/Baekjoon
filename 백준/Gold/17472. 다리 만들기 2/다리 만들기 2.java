import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st = null;

	static int N, M;
	static int map[][] = new int[100][100];
	static int set[] = new int[15000];

	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };

	static class Edge implements Comparable<Edge> {
		int i, j, cost;

		public Edge(int i, int j, int cost) {
			this.i = i;
			this.j = j;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge o) {
			// TODO Auto-generated method stub
			return this.cost - o.cost;
		}

		public String toString() {
			return "i : " + i + " " + "j : " + j + " " + "cost : " + cost + "\n";
		}
	}

	static int getParent(int x) {
		if (set[x] == x)
			return x;
		else
			return set[x] = getParent(set[x]);
	}

	static boolean find(int a, int b) {
		a = getParent(a);
		b = getParent(b);

		if (a == b)
			return true;
		else
			return false;
	}

	static void union(int a, int b) {
		a = getParent(a);
		b = getParent(b);

		if (a > b)
			set[a] = b;
		else
			set[b] = a;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int number = 2;

		// x, y, num, direction, cnt
		Queue<int[]> bridge = new LinkedList<>();

		for (int i = 0; i < 15000; i++) {
			set[i] = i;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					Queue<int[]> queue = new LinkedList<>();
					queue.add(new int[] { i, j });
					map[i][j] = number;
					while (!queue.isEmpty()) {
						int x = queue.peek()[0];
						int y = queue.peek()[1];

						queue.poll();

						for (int k = 0; k < 4; k++) {
							int tx = x + dx[k];
							int ty = y + dy[k];

							if (tx >= 0 && tx < N && ty >= 0 && ty < M) {

								if (map[tx][ty] == 1) {
									map[tx][ty] = number;
									queue.add(new int[] { tx, ty });
								} else if (map[tx][ty] == 0) {
									bridge.add(new int[] { tx, ty, number, k, 1 });
								}
							}
						}
					}
					number++;
				}
			}
		}

		List<Edge> list = new ArrayList<>();

		while (!bridge.isEmpty()) {
			int x = bridge.peek()[0];
			int y = bridge.peek()[1];
			int num = bridge.peek()[2];
			int k = bridge.peek()[3];
			int cnt = bridge.peek()[4];

			bridge.poll();

			int tx = x + dx[k];
			int ty = y + dy[k];

			if (tx >= 0 && tx < N && ty >= 0 && ty < M) {
				// 바다인 경우에 저장
				if (map[tx][ty] == 0) {
					bridge.add(new int[] { tx, ty, num, k, cnt + 1 });
				}
				// 섬인 경우에 dist 비교 후 저장
				else if (map[tx][ty] > 0 && cnt > 1) {
					list.add(new Edge(num, map[tx][ty], cnt));
				}
			}
		}
//
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < M; j++) {
//				System.out.print(map[i][j]);
//			}
//			System.out.println();
//		}

		Collections.sort(list);

		int answer = 0;
		int cnt = 0;
		for (int i = 0; i < list.size(); i++) {
			int a = list.get(i).i;
			int b = list.get(i).j;

			//System.out.println("i : " + a + " j : " + b + " cost : " + list.get(i).cost);
			if (!find(a, b)) {
				union(a, b);
				answer += list.get(i).cost;
				cnt++;
			}
		}

		if (answer == 0)
			answer = -1;

		int cnt2 = 0;
		for (int i = 2; i < number; i++) {
			if (set[i] == i)
				cnt2++;
		}
		if (cnt2 > 1)
			answer = -1;

		System.out.println(answer);
	}

}