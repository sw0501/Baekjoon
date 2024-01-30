import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	public static int N;
	public static int M;
	public static int answer = -1;
	public static int[][] arr = new int[10][10];

	public static void recursive(int row, int col, int rowDiff, int colDiff, int temp) {
		if (row >= 0 && row < N && col >= 0 && col < M) {
			int tempNum = temp * 10 + arr[row][col];

			if (tempNum > answer) {
				if (Math.sqrt(tempNum) % 1 == 0) {
					answer = tempNum;
				}
			}

			recursive(row + rowDiff, col + colDiff, rowDiff, colDiff, temp * 10 + arr[row][col]);
		}
	}

	public static void bruteForce() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				for (int k = -N + 1; k < N; k++) {
					for (int l = -M + 1; l < M; l++) {
						if (k == 0 && l == 0)
							continue;
						recursive(i, j, k, l, 0);
					}
				}
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < M; j++) {
				arr[i][j] = (int) (str.charAt(j) - '0');
			}
		}

		if (N == 1 && M == 1) {
			if (Math.sqrt(arr[0][0]) % 1 == 0) {
				answer = arr[0][0];
			}
		}
		else {
			bruteForce();
		}
			
		System.out.println(answer);
	}
}