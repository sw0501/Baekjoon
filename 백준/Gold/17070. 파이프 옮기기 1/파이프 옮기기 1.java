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

	static int N;
	static int arr[][];
	static int DP[][][];

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		N = Integer.parseInt(in.readLine());

		// 방향에 따른 경우의 개수
		DP = new int[3][17][17];
		arr = new int[17][17];

		DP[0][1][2] = 1;

		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 1; j <= N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// 가로
				if (DP[0][i][j] != 0) {
					// 가로
					if (j + 1 <= N && arr[i][j + 1] == 0) {
						DP[0][i][j + 1] += DP[0][i][j];
					}
					// 대각선
					if (i + 1 <= N && j + 1 <= N && arr[i + 1][j + 1] == 0 && arr[i + 1][j] == 0
							&& arr[i][j + 1] == 0) {
						DP[2][i + 1][j + 1] += DP[0][i][j];
					}
				}
				// 세로
				if (DP[1][i][j] != 0) {
					// 세로
					if (i + 1 <= N && arr[i + 1][j] == 0) {
						DP[1][i + 1][j] += DP[1][i][j];
					}
					// 대각선
					if (i + 1 <= N && j + 1 <= N && arr[i + 1][j + 1] == 0 && arr[i + 1][j] == 0
							&& arr[i][j + 1] == 0) {
						DP[2][i + 1][j + 1] += DP[1][i][j];
					}
				}
				// 대각선
				if (DP[2][i][j] != 0) {
					// 대각선
					if (i + 1 <= N && j + 1 <= N && arr[i][j + 1] == 0 && arr[i + 1][j + 1] == 0
							&& arr[i + 1][j] == 0) {
						DP[2][i + 1][j + 1] += DP[2][i][j];
					}
					// 가로
					if (j + 1 <= N && arr[i][j + 1] == 0) {
						DP[0][i][j + 1] += DP[2][i][j];
					}
					// 세로
					if (i + 1 <= N && arr[i + 1][j] == 0) {
						DP[1][i + 1][j] += DP[2][i][j];
					}
				}
			}
		}

		System.out.println(DP[0][N][N] + DP[1][N][N] + DP[2][N][N]);
	}
}