import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;


public class Main {

	public static int N;
	public static int M;

	public static int [][] tree;
	public static int [] ck;

	public static int DFS(int node, int target, int dist) {
		if(tree[node][target]!=0) {
			System.out.println(dist + tree[node][target]);
			return -1;
		}
		for(int i=0;i<=N;i++) {
			if(ck[i]==0 && tree[node][i]!=0) {
				ck[i] = 1;
				if(DFS(i,target,dist+tree[node][i])==-1) {
					return -1;
				}
			}
		}
		return dist;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		tree = new int[N+1][N+1];
		
		for(int i=1;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());			
			int dist = Integer.parseInt(st.nextToken());
			tree[n1][n2] = dist;
			tree[n2][n1] = dist;
		}
		
		for(int i=1;i<=M;i++) {
			ck = new int[N+1];
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			ck[n1] = 1;
			DFS(n1,n2,0);
		}
	}
}