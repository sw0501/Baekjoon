import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	public static int n, m, k;
	public static long[][] dp;
	public static int INF = 1000000000;

	public static void init() throws NumberFormatException, IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(in.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		n = n + m;
		dp = new long[n + 1][m + 1];
		dp[0][0] = 1;

		for (int i = 1; i <= n; i++) {
			dp[i][0] = 1;
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				if (dp[i][j] >= INF) {
					dp[i][j] = INF;
				}
			}
		}

		if (dp[n][m] < k) {
			System.out.println(-1);
		} else {
			for (int i = n - 1; i >= 0; i--) {
				if (dp[i][m] >= k) {
					sb.append("a");
				} else {
					sb.append("z");
					k -= dp[i][m];
					m -= 1;
				}
			}

			System.out.println(sb);
		}

	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		init();

	}
}