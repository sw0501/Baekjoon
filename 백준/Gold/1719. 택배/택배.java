import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, M;
	static int graph[][];
	static int dest[][];

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		st = new StringTokenizer(in.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		graph = new int[N + 1][N + 1];
		dest = new int[N + 1][N + 1];

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] = 10000000;
			}
		}

		for (int i = 0; i < M; i++) {
			int a, b, c;
			st = new StringTokenizer(in.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());

			graph[a][b] = c;
			graph[b][a] = c;
			dest[a][b] = b;
			dest[b][a] = a;
		}

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (i == j)
						continue;
					if (graph[i][j] > graph[i][k] + graph[k][j]) {
						dest[i][j] = dest[i][k];
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}
		
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				if(dest[i][j]==0) {
					sb.append("-");
				}
				else {
					sb.append(dest[i][j]);
				}
				sb.append(" ");
			}
			sb.append("\n");
		}
		
		System.out.println(sb);
	}

}