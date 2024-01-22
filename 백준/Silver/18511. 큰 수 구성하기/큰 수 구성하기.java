import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static int ans = 0;
	public static int N, K;
	public static int[] arr;

	public static void recursive(int num) {
		for (int i = 0; i < K; i++) {
			int temp = num * 10 + arr[i];
			if(temp<=N) {
				ans = (ans>temp?ans:temp);
				recursive(temp);
			}
		}
	}

	public static void init() throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		arr = new int[K];

		st = new StringTokenizer(in.readLine());

		for (int i = 0; i < K; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		init();
		recursive(0);
		System.out.println(ans);
	}
}
