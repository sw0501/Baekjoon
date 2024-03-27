import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st = null;
	static int N;
	static int map[][] = new int[126][126];
	static int dist[][] = new int[126][126];
	static int dx[] = { 0, 0, 1, -1 };
	static int dy[] = { 1, -1, 0, 0 };

	public static class Pos implements Comparable<Pos>{
		int x, y, cost;

		public Pos(int x, int y, int cost) {
			super();
			this.x = x;
			this.y = y;
			this.cost = cost;
		}

		@Override
		public int compareTo(Pos o) {
			// TODO Auto-generated method stub
			return o.cost - this.cost;
		}
		
		
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		int idx = 1;

		while (true) {
			N = Integer.parseInt(br.readLine());
			if (N == 0)
				break;

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					dist[i][j] = 125*9;
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			sb.append("Problem ").append(idx++).append(": ").append(dijkstra()).append("\n");

		}
		System.out.println(sb);
	}

	private static int dijkstra() {
		// TODO Auto-generated method stub
		dist[0][0] = map[0][0];

		PriorityQueue<Pos> pq = new PriorityQueue<>();
		pq.add(new Pos(0, 0, -map[0][0]));

		while (!pq.isEmpty()) {
			Pos p = pq.poll();
			p.cost = -p.cost;

			for (int k = 0; k < 4; k++) {
				int tx = p.x + dx[k];
				int ty = p.y + dy[k];

				if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
					int tcost = p.cost + map[tx][ty];
					if (tcost < dist[tx][ty]) {
						dist[tx][ty] = tcost;
						pq.add(new Pos(tx, ty, -tcost));
					}
				}
			}
		}

		return dist[N - 1][N - 1];
	}

}