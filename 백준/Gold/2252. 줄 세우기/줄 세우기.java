import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int n, m;
	static int[] indegree;
	static List<List<Integer>> graph = new ArrayList<>();

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		indegree = new int[n + 1];

		for (int i = 0; i <= n; i++) {
			graph.add(new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			indegree[b]++;
			graph.get(a).add(b);
		}

		topologySort();
	}

	private static void topologySort() {
		List<Integer> ans = new ArrayList<Integer>();
		Queue<Integer> q = new LinkedList<>();

		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0)
				q.add(i);
		}

		while (!q.isEmpty()) {
			int cur = q.poll();
			ans.add(cur);

			for (int i = 0; i < graph.get(cur).size(); i++) {
				int tmp = graph.get(cur).get(i);
				indegree[tmp] --;
				if(indegree[tmp] == 0) {
					q.add(tmp);
				}
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0 ; i < ans.size(); i ++) {
			sb.append(ans.get(i)).append(" ");
		}
		System.out.println(sb);
	}
}