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

		int T = Integer.parseInt(in.readLine());

		int DP[][] = new int[31][31];

		DP[0][0] = 1;
		for (int i = 1; i < 31; i++) {
			DP[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				DP[i][j] = DP[i-1][j] + DP[i-1][j-1];
			}
		}


		for (int t = 0; t < T; t++) {
			st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			
			sb.append(DP[M][N]).append("\n");
		}
		System.out.println(sb);
	}
}