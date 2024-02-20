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

	static List<List<Integer>> graph = new LinkedList<>();
	static int N, M;
	static int degree[] = new int[32001];

	static void topology_sort() {
		Queue<Integer> queue = new LinkedList<>();

		for (int i = 1; i <= N; i++) {
			if (degree[i] == 0)
				queue.add(i);
		}
		
		while(!queue.isEmpty()) {
			int x = queue.poll();
			sb.append(x).append(" ");

			for (int num : graph.get(x)) {
				if (--degree[num] == 0) {
					queue.add(num);
				}
			}
		}
//
//		for (int i = 1; i <= N; i++) {
//			if (queue.isEmpty()) {
//				continue;
//			}
//			int x = queue.poll();
//			sb.append(x).append(" ");
//
//			for (int num : graph.get(x)) {
//				if (--degree[num] == 0) {
//					queue.add(num);
//				}
//			}
//		}
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		for (int i = 0; i <= N; i++) {
			graph.add(new LinkedList<>());
		}

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			graph.get(a).add(b);
			degree[b]++;
		}

		topology_sort();

		System.out.println(sb);
	}
}