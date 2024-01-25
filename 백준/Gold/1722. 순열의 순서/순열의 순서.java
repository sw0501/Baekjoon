import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	public static int N, T;
	public static long K;
	public static long[] dp;
	public static boolean[] ck;
	public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static StringBuilder sb = new StringBuilder();
	public static StringTokenizer st;

	public static void init() throws NumberFormatException, IOException {

		Scanner sc = new Scanner(System.in);
		
		st = new StringTokenizer(in.readLine());

		N = Integer.parseInt(st.nextToken());

		dp = new long[N + 1];
		
		dp[1] = 1;
		
		if(N>1) {
			dp[2] = 1;
			for (int i = 3; i <= N; i++) {
				dp[i] = dp[i - 1] * (i - 1);
			}
		}
		

		st = new StringTokenizer(in.readLine());

		T = Integer.parseInt(st.nextToken());

		if (T == 1) {
			K =  Long.parseLong(st.nextToken());
			prob1();
		}
		else {
			List<Integer>list = new ArrayList<>();
			for(int i=0;i<N;i++) {
				list.add(Integer.parseInt(st.nextToken()));
			}
			prob2(list);
		}
	}

	public static void prob1() {

		List<Integer> list = new ArrayList<>();

		for (int i = 1; i <= N; i++) {
			list.add(i);
		}

		for (int i = N; i >= 1; i--) {
			for (int j = list.size(); j >= 0; j--) {
				long temp = dp[i] * j;

				if (K > temp) {
					System.out.print(list.get(j) + " ");
					list.remove(j);
					K -= temp;
					K = K < 0 ? 0 : K;
					break;
				}
			}
		}
	}

	public static void prob2(List<Integer>list) {
		ck = new boolean[N + 1];
		
		long num = 1;
		
		for(int i=N;i>=1;i--) {
			long temp = 0;
			for(int j=1;j<=N;j++) {
				if(ck[j])continue;
				if(list.get(0)==j) {
					num += temp;
					ck[j] = true;
					list.remove(0);
					break;
				}
				temp += dp[i];
			}
		}
		
		System.out.println(num);
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		init();

	}
}
