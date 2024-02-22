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

	static int N;

	static int p[][];

	static int order[] = new int[10];
	static boolean visit[] = new boolean[10];
	static int ans = 0;

	static void play() {
		int tempScore = 0;

		int idx = 1;

		// 이닝 진행
		for (int i = 0; i < N; i++) {

			int out = 0;
			boolean base[] = new boolean[4];

			// 아웃 카운트 3일때까지 반복
			while (out < 3) {
				if (p[i][order[idx]] == 0) {
					out++;
				}
				else {
					for (int k = 3; k >= 1; k--) {
						// 주자가 있는 경우
						if (base[k]) {
							// 홈 밟은 경우 점수 획득
							if (k + p[i][order[idx]] >= 4) {
								tempScore++;
								base[k] = false;
							}
							// 베이스 이동
							else {
								base[k + p[i][order[idx]]] = true;
								base[k] = false;
							}
						}
					}
					// 타자 이동
					// 홈런인 경우
					if (p[i][order[idx]] == 4) {
						tempScore++;
					}
					// 베이스 이동
					else {
						base[p[i][order[idx]]] = true;
					}
				}
				
				//주자 변경
				idx++;
				if (idx == 10)
					idx = 1;
			}
		}
		ans = Math.max(ans, tempScore);
		
	}

	static void select(int cnt) {
		if (cnt == 10) {
			play();
		}

		// 4번 타자는 이미 지정
		if (cnt == 4)
			select(cnt + 1);
		else {
			for (int i = 2; i <= 9; i++) {
				if (!visit[i]) {
					visit[i] = true;
					order[cnt] = i;
					select(cnt + 1);
					visit[i] = false;
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(in.readLine());

		p = new int[N][10];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 1; j <= 9; j++) {
				p[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		visit[1] = true;
		order[4] = 1;

		select(1);

		System.out.println(ans);
	}
}