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

	public static int N, op;

	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(in.readLine());

		PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				// TODO Auto-generated method stub
				if (Math.abs(o1) == Math.abs(o2)) {
					return o1 - o2;
				}
				return Math.abs(o1) - Math.abs(o2);
			}
		});

		for (int i = 0; i < N; i++) {
			op = Integer.parseInt(in.readLine());
			if (op == 0) {
				if (pq.isEmpty()) {
					sb.append(0);
				} else {
					sb.append(pq.poll());
				}
				sb.append("\n");
			} else {
				pq.add(op);
			}
		}

		System.out.println(sb);
	}
}