import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	public static int N;

	public static long[] DP = new long[10001];
	public static List<Integer> coin = new ArrayList<Integer>();

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int N = Integer.parseInt(br.readLine());

			for (int i = 0; i <= 10000; i++) {
				DP[i] = 0;
			}

			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				coin.add(Integer.parseInt(st.nextToken()));
			}

			int M = Integer.parseInt(br.readLine());

			DP[0] = 1;
			for (Integer i : coin) {
				// i원 동전 개수를 바탕으로 만들 수 있는 방법의 수
				for (int j = i; j <= M; j++) {
					DP[j] += DP[j - i];
				}
			}
			
			sb.append(DP[M]).append("\n");
			coin.clear();
		}
		
		System.out.println(sb);
	}
}