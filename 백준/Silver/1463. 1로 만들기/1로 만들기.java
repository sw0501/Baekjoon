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

		
		int N = Integer.parseInt(in.readLine());
		int DP[] = new int[1000001];

		for (int i = 1000000; i >= 1; i--) {
			DP[i] = 123456789;
		}

		DP[N] = 0;
		// 해당 수로 갈 수 있는 경우겠네?

		for (int i = N; i > 1; i--) {
			// 3 나누기
			if (i % 3 == 0) {
				DP[i / 3] = Math.min(DP[i / 3], DP[i] + 1);
			}

			// 2 나누기
			if (i % 2 == 0) {
				DP[i / 2] = Math.min(DP[i / 2], DP[i] + 1);
			}
			
			// 1 빼기
			DP[i - 1] = Math.min(DP[i - 1], DP[i] + 1);
		}
		
		System.out.println(DP[1]);
	}
}