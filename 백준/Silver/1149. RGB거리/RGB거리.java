import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		int N;

		N = Integer.parseInt(in.readLine());

		int DP_R[] = new int[N + 1];
		int DP_G[] = new int[N + 1];
		int DP_B[] = new int[N + 1];

		int v[][] = new int[N+1][3];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());

			v[i][0] = Integer.parseInt(st.nextToken());
			v[i][1] = Integer.parseInt(st.nextToken());
			v[i][2] = Integer.parseInt(st.nextToken());
		}

		DP_R[0] = v[0][0];
		DP_G[0] = v[0][1];
		DP_B[0] = v[0][2];
		for (int i = 1; i < N; i++) {
			DP_R[i] = v[i][0] + Math.min(DP_G[i-1], DP_B[i-1]);
			DP_G[i] = v[i][1] + Math.min(DP_R[i-1], DP_B[i-1]);
			DP_B[i] = v[i][2] + Math.min(DP_R[i-1], DP_G[i-1]);
		}

		System.out.println(Math.min(Math.min(DP_R[N-1], DP_G[N - 1]), DP_B[N - 1]));
		
	}
}