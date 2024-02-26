import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N;

	static class Pair {
		int score, t;

		public Pair(int score, int t) {
			super();
			this.score = score;
			this.t = t;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		N = Integer.parseInt(in.readLine());
		int score = 0;

		// 스택
		Stack<Pair> stack = new Stack<>();

		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(in.readLine());
			int op, A, T;
			op = Integer.parseInt(st.nextToken());

			if (op == 0) {
				// 이미 진행중인 업무가 있는 경우
				if (!stack.isEmpty()) {
					// 진행중이던 업무가 끝난 경우
					if (--stack.peek().t == 0) {
						score += stack.peek().score;
						stack.pop();
					}
				}
			}

			else {
				A = Integer.parseInt(st.nextToken());
				T = Integer.parseInt(st.nextToken()) - 1;
				if(T == 0) {
					score += A;
				}
				else {
					stack.push(new Pair(A, T));
				}
			}
		}
		
		System.out.println(score);
	}
}