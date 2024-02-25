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

	static class Edge implements Comparable<Edge> {
		int start, dest;

		public Edge(int start, int dest, int dist) {
			super();
			this.start = start;
			this.dest = dest;
			this.dist = dist;
		}

		int dist;

		@Override
		public int compareTo(Edge o) {
			// TODO Auto-generated method stub
			return this.dist - o.dist;
		}
	}

	static int set[] = new int[100001];

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

		for (int i = 1; i <= N; i++) {
			set[i] = i;
		}

		Edge[] edge = new Edge[M];
		long totalCost = 0;
		long minCost = 0;
		int a, b, d;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(in.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());

			totalCost += d;
			edge[i] = new Edge(a, b, d);
		}

		Arrays.sort(edge);

		int cnt = 0;

		for (int i = 0; i < edge.length; i++) {
			if (!find(edge[i].start, edge[i].dest)) {
				cnt++;
				unionParent(edge[i].start, edge[i].dest);
				minCost += edge[i].dist;
			}
			if(cnt==N-1) {
				break;
			}
		}
		
		if(cnt != N-1) {
			System.out.println(-1);
		}
		else {
			System.out.println(totalCost - minCost);
		}

		
	}
}