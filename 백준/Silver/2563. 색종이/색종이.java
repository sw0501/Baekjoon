import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static StringBuilder sb = new StringBuilder();
	public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer st;

	public static void main(String[] args) throws IOException {

		int[][] board = new int[101][101];

		int ans = 0;

		int N = Integer.parseInt(in.readLine());

		for (int n = 1; n <= N; n++) {
			st = new StringTokenizer(in.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());

			for (int i = x; i < x + 10; i++) {
				for (int j = y; j < y + 10; j++) {
					board[i][j] = 1;
				}
			}
		}
		
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				ans += board[i][j];
			}
		}

		System.out.println(ans);
	}
}