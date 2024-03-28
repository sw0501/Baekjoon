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

	static int R, C;
	static char map[][] = new char[50][50];
	static boolean visit[][] = new boolean[50][50];

	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };

	static class Pos{
		int x,y,cnt;

		public Pos(int x, int y, int cnt) {
			super();
			this.x = x;
			this.y = y;
			this.cnt = cnt;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		st = new StringTokenizer(br.readLine());

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		Pos start= null;
		Pos dest = null;
		List<Pos> waterList = new ArrayList<>();
		
		for (int i = 0; i < R; i++) {
			String str = br.readLine();
			for (int j = 0; j < C; j++) {
				map[i][j] = str.charAt(j);
				
				if(map[i][j] == 'D') {
					dest = new Pos(i,j,0);
				}
				else if(map[i][j] == '*') {
					Pos water = new Pos(i,j,-1);
					waterList.add(water);
				}
				else if(map[i][j] == 'S') {
					start = new Pos(i,j,0);
				}
			}
		}
		
		Queue<Pos>queue = new LinkedList<>();
		
		for(Pos water: waterList) {
			queue.add(water);
			visit[water.x][water.y] = true;
		}
		
		queue.add(start);
		visit[start.x][start.y] = true;
		
		while(!queue.isEmpty()) {
			Pos p = queue.poll();
			
			for(int k=0;k<4;k++) {
				int tx = p.x + dx[k];
				int ty = p.y + dy[k];
				
				if(tx>=0&&tx<R&&ty>=0&&ty<C) {
					if(visit[tx][ty] || map[tx][ty]=='X')continue;

					//물인 경우
					if(p.cnt<0) {
						if(map[tx][ty]=='.') {
							visit[tx][ty] = true;
							queue.add(new Pos(tx,ty,p.cnt));
						}
					}
					else {
						if(map[tx][ty]=='.') {
							visit[tx][ty] = true;
							queue.add(new Pos(tx,ty,p.cnt + 1));
						}
						else if(map[tx][ty] == 'D') {
							System.out.println(p.cnt+1);
							
							return ;
						}
					}
				}
			}
		}
		
		System.out.println("KAKTUS");
		
	}

}