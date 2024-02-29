import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair {
	int first;
	int second;
	public Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}
	
}
public class Main {

    static int          N;
    static int			M;
    static int[][]		board 	= new int[9][9];    
    static int[][]		copy 	= new int[9][9];    
    static boolean[][]	visited = new boolean[9][9];
    static final int[]	dx 		= {-1, 0, 1, 0};
    static final int[]	dy 		= {0, 1, 0, -1};
    static int			ans 	= 0;

    public static void main(String[] args) throws Exception {
//        System.setIn(new FileInputStream("input.txt"));
        BufferedReader      br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder       sb = new StringBuilder();
        StringTokenizer     st;
        
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        for (int i = 1; i <= N; i++) {
        	st = new StringTokenizer(br.readLine());
        	for (int j = 1; j <= M; j++) {
        		board[i][j] = Integer.parseInt(st.nextToken());
        		copy[i][j] = board[i][j];
        	}
        }
        
        for (int x1 = 1; x1 <= N; x1++) {
        	for (int y1 = 1; y1 <= M; y1++) {
        		for (int x2 = 1; x2 <= N; x2++) {
                	for (int y2 = 1; y2 <= M; y2++) {                		
                		if (x1 == x2 && y1 == y2) continue;
                		
                		for (int x3 = 1; x3 <= N; x3++) {
                        	for (int y3 = 1; y3 <= M; y3++) {
                        		if (x1 == x3 && y1 == y3) continue;
                        		if (x2 == x3 && y2 == y3) continue;
                        		if (board[x1][y1] != 0 || board[x2][y2] != 0 || board[x3][y3] != 0) continue;                        		
                        		board[x1][y1] = 1;
                        		board[x2][y2] = 1;
                        		board[x3][y3] = 1;                        		
                        		ans = Math.max(ans, bfs());                 
                        		init();
                        	}
                        }
                	}
                }
        	}
        }
        System.out.println(ans);
        
    }
    static void init() {
    	for (int i = 1; i <= N; i++) {
    		for (int j = 1; j <= M; j++) {
    			board[i][j] = copy[i][j];
    			visited[i][j] = false;
    		}
    	}
    }
    static void printBoard() {
    	for (int i = 1; i <= N; i++) {
    		for (int j = 1; j <= M; j++) {
    			System.out.print(board[i][j] + " ");
    		}
    		System.out.println();
    	}
    	System.out.println();
    }
    
    static int bfs() {
    	int ret = 0;    	
    	Queue<Pair> q = new ArrayDeque<>();    	
    	
    	for (int i = 1; i <= N; i++) {
    		for (int j = 1; j <= M; j++) {
    			if (board[i][j] == 2) {
    				q.add(new Pair(i, j));
    				visited[i][j] = true;
    			}
    		}
    	}
    	
    	while (!q.isEmpty()) {
    		int x = q.peek().first;
    		int y = q.peek().second;
    		q.poll();
    		for (int k = 0; k < 4; k++) {
    			int nx = x + dx[k];
    			int ny = y + dy[k];
    			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
    			if (visited[nx][ny]) continue;
    			if (board[nx][ny] != 0) continue;
    			visited[nx][ny] = true;
    			board[nx][ny] = 2;
    			q.add(new Pair(nx, ny));
    		}
    	}
    	
    	for (int i = 1; i <= N; i++) {
    		for (int j = 1; j <= M; j++) {
    			if (board[i][j] == 0) ret++;
    		}
    	}
    	
        	
    	return ret;    	
    }
}