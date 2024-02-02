import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static int[] leastNum = new int[4];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		
		Queue<Integer> queue = new LinkedList<Integer>();
		
		for(int i=1;i<=N;i++) {
			queue.add(i);
		}
		
		while(queue.size()>=2) {
			queue.poll();
			queue.add(queue.poll());
		}

		System.out.println(queue.peek());

	}
}