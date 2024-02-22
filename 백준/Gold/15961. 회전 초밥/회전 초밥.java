import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
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

	static int N, d, k, c;
	static int arr[];

	static int ans = -1;
	static int dish[];

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(in.readLine());

		N = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());

		arr = new int[N];
		dish = new int[d + 1];

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(in.readLine());
		}

		int i = 0, j = 0;
		int tempCnt = 1;
		dish[c]++;
		for (j = 0; j < k; j++) {
			// 처음 먹는 초밥
			if (dish[arr[j]] == 0) {
				tempCnt++;
			}
			dish[arr[j]]++;
		}

		ans = Math.max(ans, tempCnt);

		for (j = k; i < N; j++, i++) {
			//회전
			if (j == N)
				j = 0;
			
			// 기존에 고르는 초밥 제거
			dish[arr[i]]--;
			if (dish[arr[i]] == 0)
				tempCnt--;

			// 처음 먹는 초밥 카운트
			if (dish[arr[j]] == 0) {
				tempCnt++;
			}
			dish[arr[j]]++;

			ans = Math.max(ans, tempCnt);
		}

		System.out.println(ans);
	}
}