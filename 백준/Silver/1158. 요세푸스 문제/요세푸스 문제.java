import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());

		Queue<Integer> queue = new LinkedList<>();

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		for (int i = 1; i <= N; i++) {
			queue.add(i);
		}

		sb.append("<");
		int idx = 0;
		while (!queue.isEmpty()) {
			idx++;
			if(idx%K==0) {
				sb.append(queue.poll());
				if(!queue.isEmpty()) {
					sb.append(", ");
				}
			}
			else {
				queue.add(queue.poll());
			}
			idx %=K;
		}
		sb.append(">");
		System.out.println(sb);
	}
}