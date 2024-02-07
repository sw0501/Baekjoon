import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
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

	public static class Class {
		int num;
		int start;
		int end;
		int time;

		Class(int num, int start, int end) {
			this.num = num;
			this.start = start;
			this.end = end;
			this.time = end - start;
		}

		@Override
		public String toString() {
			// TODO Auto-generated method stub

			return num + " " + start + " " + end;
		}
	}

	public static List<Class> list = new ArrayList<>();

	public static void main(String[] args) throws IOException {

		int N = Integer.parseInt(in.readLine());

		PriorityQueue<Class> pq = new PriorityQueue<>(new Comparator<Class>() {

			@Override
			public int compare(Class o1, Class o2) {
				// TODO Auto-generated method stub
				return o1.start - o2.start;
			}
		});

		PriorityQueue<Class> room = new PriorityQueue<>(new Comparator<Class>() {

			@Override
			public int compare(Class o1, Class o2) {
				// TODO Auto-generated method stub
				return o1.end - o2.end;
			}
		});

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			int num = Integer.parseInt(st.nextToken());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());

			pq.add(new Class(num, start, end));
		}

		for (int i = 0; i < N; i++) {
			if (room.isEmpty()) {
				room.add(pq.poll());
			} else {
				//System.out.println("Room" + room.peek());
				//System.out.println("Peek" + pq.peek());
				if (room.peek().end <= pq.peek().start) {
					room.poll();
					room.add(pq.poll());
				} else {
					room.add(pq.poll());
				}
			}
		}

		System.out.println(room.size());

//		
//		while (!room.isEmpty()) {
//			System.out.println(room.poll());
//		}
		

		// 시작 시간, 종료 시간, 강의 시간 우선으로

	}
}