import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, M, K;

	static int dist[] = new int[50001];
	static boolean visit[] = new boolean[50001];

	static class Pair {
		int node, dist;

		public Pair(int x, int y) {
			super();
			this.node = x;
			this.dist = y;
		}
	}

	static List<Pair>[] list;

	static void dijkstra(int start) {
		dist[start] = 0;

		PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {

			@Override
			public int compare(Pair o1, Pair o2) {
				// TODO Auto-generated method stub
				return o1.dist - o2.dist;
			}
		});

		pq.add(new Pair(start, 0));

		while (!pq.isEmpty()) {
			Pair p = pq.poll();

			for (Pair temp : list[p.node]) {
				if (dist[temp.node] > p.dist + temp.dist) {
					dist[temp.node] = p.dist + temp.dist;
					pq.add(new Pair(temp.node, dist[temp.node]));
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			System.out.println((dist[i] == 123456789 ? "INF" : dist[i]));
		}

	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		st = new StringTokenizer(in.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		K = Integer.parseInt(in.readLine());

		list = new ArrayList[N + 1];

		for (int i = 0; i <= N; i++) {
			dist[i] = 123456789;
			list[i] = new ArrayList<>();
		}

		int a, b, c;

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(in.readLine());

			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());

			list[a].add(new Pair(b, c));
		}

		dijkstra(K);

	}
}