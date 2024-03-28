import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
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

	static int T;
	static int N;

	static class Pos {
		int x, y;

		public Pos(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		T = Integer.parseInt(br.readLine());

		for (int t = 0; t < T; t++) {

			Queue<Pos> queue = new LinkedList<>();
			N = Integer.parseInt(br.readLine());

			Pos start = null;
			List<Pos> list = new ArrayList<>();
			Pos end = null;

			int x = 0, y = 0;

			st = new StringTokenizer(br.readLine());

			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());

			start = new Pos(x, y);

			queue.add(start);

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());

				x = Integer.parseInt(st.nextToken());
				y = Integer.parseInt(st.nextToken());

				list.add(new Pos(x, y));
			}

			st = new StringTokenizer(br.readLine());

			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());

			end = new Pos(x, y);
			
			list.add(end);
			
			int size = list.size();
			
			boolean visit[] = new boolean[150];
			
			while(!queue.isEmpty()) {
				
				Pos p = queue.poll();
				if(p.x == end.x && p.y == end.y) {
					break;
				}
				
				for(int i=0;i<size;i++) {
					if(visit[i] || (Math.abs((p.x - list.get(i).x)) + Math.abs((p.y - list.get(i).y)) > 1000))continue;
					else {
						visit[i] = true;
						queue.add(new Pos(list.get(i).x,list.get(i).y));
					}
				}
				
			}
			if(visit[N]) {
				System.out.println("happy");
			}
			else {
				System.out.println("sad");
			}
		}

	}

}