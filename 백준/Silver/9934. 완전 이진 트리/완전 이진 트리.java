import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[] tree;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));	
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static Queue<Integer> queue = new LinkedList<Integer>();
	
	public static void init() throws NumberFormatException, IOException {

		st = new StringTokenizer(in.readLine());
		
		N = Integer.parseInt(st.nextToken());
		tree = new int[4001];
		
		st = new StringTokenizer(in.readLine());
		
		preOrder(1,1);
		
		int height = 2;
		
		queue.add(1);
		while(!queue.isEmpty()) {
			int root = queue.remove();
			sb.append(tree[root] + " ");
			
			if(height != Math.pow(2,N)) {
				queue.add(2*root);
				queue.add(2*root+1);
			}
			
			//레벨이 달라진 경우
			if(root+1 == height) {
				sb.append("\n");
				height *=2;
			}
			
		}
		
		System.out.println(sb);
	}
	
	static void preOrder(int height, int root) {
		if(height<N) {
			preOrder(height + 1, 2*root);
			tree[root] = Integer.parseInt(st.nextToken());
			preOrder(height + 1, 2*root+1);
		}
		else {
			tree[root] = Integer.parseInt(st.nextToken());
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		init();

	}
}
