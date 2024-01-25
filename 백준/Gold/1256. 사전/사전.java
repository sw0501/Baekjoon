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
		
		//n,m,k 입력
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		n = n + m;
		dp = new long[n + 1][m + 1];
		dp[0][0] = 1;

		//조합 DP로 계산
		for (int i = 1; i <= n; i++) {
			dp[i][0] = 1;
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				if (dp[i][j] >= INF) {
					dp[i][j] = INF;
				}
			}
		}

		//k가 조합의 개수보다 크다면
		if (dp[n][m] < k) {
			System.out.println(-1);
		} else {
			//맨 앞자리부터 계산 
			//dp[i][m] -> 앞자리에 a를 둔 상태에서 나머지 조합의 개수
			//dp[i][m] >= k -> k보다 크다면 
			//[a ~~~]  <= k번째 문자열 < [z ~~~] 가 되기 때문에 반드시 앞자리에 a가 와야됨
			//작다면 z 추가 후 앞자리가 a인 조합의 개수만큼 k 감소
			//z를 추가했으므로 m도 1 감소
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