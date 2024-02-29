import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.math.*;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int			ans			= 987654321;
    static int          N;
    static int[][]		prices 		= new int[11][11];
    static boolean[]	visited 	= new boolean[11];

    public static void main(String[] args) throws Exception {
//        System.setIn(new FileInputStream("input.txt"));
        BufferedReader      br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder       sb = new StringBuilder();
        StringTokenizer     st;
        
        N = Integer.parseInt(br.readLine());
        for (int i = 1; i <= N; i++) {
        	st = new StringTokenizer(br.readLine());
        	for (int j = 1; j <= N; j++) {
        		prices[i][j] = Integer.parseInt(st.nextToken());
        	}
        }
        
    
    	visited[1] = true;
    	traverse(1, 1, 1, 0);
    	        	
        System.out.println(ans);
    }
    
    static void traverse(int cur, int count, int start, int sum) {
    	if (count == N) {
    		if (prices[cur][start] != 0) {
    			sum += prices[cur][start];
    			ans = Math.min(ans, sum);    			
    		}
    		return;
    	}
    	for (int i = 1; i <= N; i++) {
    		if (visited[i]) continue;
    		if (prices[cur][i] == 0) continue;
    		visited[i] = true;    		
    		traverse(i, count + 1, start, sum + prices[cur][i]);
    		visited[i] = false;
    	}
    	
    }
}