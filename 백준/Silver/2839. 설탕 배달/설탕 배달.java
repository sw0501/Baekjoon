import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static StringBuilder sb = new StringBuilder();

	public static int N;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(in.readLine());

		int a = 3, b = 5;
		int ans = 0;
		int min = N / 5;

		for (int i = min; i >= 0; i--) {
			if ((N - 5 * i) % 3 == 0) {
				ans = i + ((N - 5 * i) / 3);
				break;
			}
		}

		if (ans == 0) {
			ans = -1;
		}
		System.out.println(ans);
	}
}