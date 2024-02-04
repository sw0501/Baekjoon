import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static StringBuilder sb = new StringBuilder();
	public static StringTokenizer st;

	public static int N;
	public static int[][] S;
	public static int ans = Integer.MAX_VALUE;

	public static void combination() {

	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		N = Integer.parseInt(in.readLine());
		S = new int[N + 1][N + 1];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < N; j++) {
				S[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// 비트마스킹
		for (int i = 1; i < (1 << N); i++) {
			// 1 ~ N원소 비교
			int[] team = new int[2];

			for (int j = 0; j < N; j++) {
				for (int k = j + 1; k < N; k++) {
					// j번째 선수와 k번째 선수가 같은 팀에 속해 있다면
					if ((i & (1 << j)) != 0 && (i & (1 << k)) != 0) {
						team[1] += S[j][k] + S[k][j];
					} else if ((i & (1 << j)) == 0 && (i & (1 << k)) == 0) {
						team[0] += S[j][k] + S[k][j];
					}
				}
			}
			int diff = Math.abs(team[0] - team[1]);
			ans = (ans > diff ? diff : ans);
		}

		System.out.println(ans);
	}
}
