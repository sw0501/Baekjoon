import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int[] arr = new int[N + 1];
		int[] DP = new int[N + 1];

		st = new StringTokenizer(br.readLine());

		for (int i = 1; i <= N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			DP[i] = DP[i - 1] + arr[i];
		}

		int start,end;
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(br.readLine());
			start = Integer.parseInt(st.nextToken());
			end = Integer.parseInt(st.nextToken());
			
			sb.append(DP[end]-DP[start-1]).append("\n");
		}
		
		System.out.println(sb);
	}

}