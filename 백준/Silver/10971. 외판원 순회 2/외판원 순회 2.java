import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N;
	static int dist[][];
	static boolean visit[];
	static int minCost = Integer.MAX_VALUE;

	static void select(int start, int city, int cnt, int cost) {
		
		visit[city] = true;
		if (cnt == N-1) {
			if(dist[city][start] !=0) {
				minCost = Math.min(minCost, cost + dist[city][start]);	
			}
		}

		for (int i = 0; i < N; i++) {
			if (!visit[i] && dist[city][i] != 0) {
				select(start, i, cnt + 1, cost + dist[city][i]);
			}
		}

		visit[city] = false;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		N = Integer.parseInt(in.readLine());
		dist = new int[N][N];
		visit = new boolean[N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < N; j++) {
				dist[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < N; i++) {
			select(i, i, 0, 0);
		}

		System.out.println(minCost);
	}
}