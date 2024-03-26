import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static int n;
	static int[][] board;
	static boolean[][] visited;
	static int[][] dist;
	static int[] ry = {0, 0, 1, -1};
	static int[] rx = {1, -1, 0, 0};
	static final int INF= 987654321;
	static int answer;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int index = 1;
		
		while((n= Integer.parseInt(br.readLine())) != 0) {
			board = new int[n][n];
			dist = new int[n][n];
			visited = new boolean[n][n];
			answer = 0;
			
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < n; j++) {
					int num = Integer.parseInt(st.nextToken());
					board[i][j] = num;
				}
			}
			
			answer = dijkstra(new int[] {0, 0});
			
			sb.append("Problem ");
			sb.append(index);
			sb.append(": ");
			sb.append(answer).append("\n");
			
			index ++;
		}
		
		System.out.println(sb);
		
	}
	
	static int dijkstra(int[] start) {
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = INF;
			}
		}
		
		PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> {
			return Integer.compare(o1[2], o2[2]);
		});
		
		dist[start[0]][start[1]] = board[start[0]][start[1]];
		pq.add(new int[] {start[0], start[1], dist[start[0]][start[1]]});
		
		while(!pq.isEmpty()) {
			int[] now = pq.poll();
			
			if(now[0] == n-1 && now[1] == n-1) return dist[n-1][n-1];
			
			if(visited[now[0]][now[1]]) continue;
			visited[now[0]][now[1]] = true;
			
			for (int i = 0; i < 4; i++) {
				int r = now[0] + ry[i];
				int c = now[1] + rx[i];
				
				if(r < 0 || c< 0 || r>= n || c>= n) continue;
				
				if(dist[r][c] > dist[now[0]][now[1]] + board[r][c]) {
					dist[r][c] = dist[now[0]][now[1]] + board[r][c];
					pq.add(new int[] {r, c, dist[r][c]});
				}
			}
			
		}
		
		
//		return dist[n-1][n-1];
		return -1;
		
	}
}