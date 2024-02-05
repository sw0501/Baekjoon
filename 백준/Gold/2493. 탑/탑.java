import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static int[] leastNum = new int[4];

	public static class Top {
		int height;
		int index;

		public Top(int height, int index) {
			this.height = height;
			this.index = index;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		Stack<Top> stack = new Stack<>();
		Queue<Integer> queue = new LinkedList<>();
		int N = Integer.parseInt(br.readLine());

		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			if (stack.isEmpty()) {
				stack.push(new Top(Integer.parseInt(st.nextToken()), i + 1));
				sb.append(0).append(" ");
			} else {
				int height = Integer.parseInt(st.nextToken());
				while (!stack.isEmpty() && stack.peek().height < height) {
					stack.pop();
				}
				if (stack.isEmpty()) {
					sb.append(0).append(" ");
				} else {
					sb.append(stack.peek().index).append(" ");
				}
				stack.push(new Top(height, i + 1));
			}
		}

		System.out.println(sb);
	}
}