import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	public static int N;
	public static long sheep = 0;
	public static List<List<Integer>> tree;
	public static boolean[] visit;
	public static long[] cnt;

	public static long DFS(int root, long wolf) {

		if (cnt[root] > 0) {
			sheep += (cnt[root] + wolf > 0 ? cnt[root] + wolf : 0);
			wolf += cnt[root];
			wolf = (wolf > 0 ? 0 : wolf);
		} else {
			wolf += cnt[root];
		}

		visit[root] = true;
		for (Integer i : tree.get(root)) {
			if (!visit[i]) {
				long temp = DFS(i, wolf);
				if(temp > wolf) {
					wolf = temp;
				}
			}
		}
		visit[root] = false;
		
		return wolf;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		N = Integer.parseInt(br.readLine());

		tree = new ArrayList<>();
		for (int i = 0; i <= N; i++) {
			tree.add(new ArrayList<Integer>());
		}
		cnt = new long[N + 1];
		visit = new boolean[N + 1];

		for (int i = 2; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			String animal = st.nextToken();
			if (animal.equals("S")) {
				cnt[i] = Integer.parseInt(st.nextToken());
				int road = Integer.parseInt(st.nextToken());
				tree.get(road).add(i);
				tree.get(i).add(road);
			} else {
				cnt[i] = -Integer.parseInt(st.nextToken());
				int road = Integer.parseInt(st.nextToken());
				tree.get(road).add(i);
				tree.get(i).add(road);
			}
		}

		DFS(1, 0);

		System.out.println(sheep);
	}

}