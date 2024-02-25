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

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int count = 0;
		
		LinkedList<Integer> deque = new LinkedList<>();

		for (int i = 1; i <= N; i++) {
			deque.add(i);
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) {
			int num = Integer.parseInt(st.nextToken());
			int idx = deque.indexOf(num);
			int half = deque.size();
			if (half % 2 == 0)
				half = half / 2 - 1;
			else
				half = half / 2;

			if (idx <= half) {
				
				for (int j = 0; j < idx; j++) {
					deque.offerLast(deque.pollFirst());
					count++;
				}
				deque.pollFirst();
			}
			else {
				for (int j = 0; j < deque.size() - idx; j++) {
					deque.offerFirst(deque.pollLast());
					count++;
				}
				deque.pollFirst();
			}
		}
		
		System.out.println(count);
	}
}