import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int[][] DP = new int[N + 1][N + 1];

		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) {
				DP[i][j] = (short)Integer.parseInt(st.nextToken());
				DP[i][j] += DP[i][j - 1] + DP[i - 1][j] - DP[i - 1][j - 1];
			}

		}

		int startX, startY, endX, endY, temp;
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(br.readLine());
			startX = Integer.parseInt(st.nextToken());
			startY = Integer.parseInt(st.nextToken());
			endX = Integer.parseInt(st.nextToken());
			endY = Integer.parseInt(st.nextToken());

			temp = DP[endX][endY] - DP[startX - 1][endY] - DP[endX][startY - 1] + DP[startX - 1][startY - 1];
			sb.append(temp).append("\n");
		}

		System.out.println(sb);
	}

}