import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static StringBuilder sb = new StringBuilder();

	static int T, K;
	static PriorityQueue<Long> pq;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		T = Integer.parseInt(in.readLine());

		for (int t = 1; t <= T; t++) {
			long ans = 0;
			K = Integer.parseInt(in.readLine());

			pq = new PriorityQueue<>();
			StringTokenizer st = new StringTokenizer(in.readLine());
			for (int i = 0; i < K; i++) {
				pq.add(Long.parseLong(st.nextToken()));
			}

			while (pq.size() > 1) {
				long a = pq.poll();
				long b = pq.poll();
				ans += a + b;
				pq.add(a + b);
			}

			sb.append(ans).append("\n");
		}

		System.out.println(sb);
	}
}