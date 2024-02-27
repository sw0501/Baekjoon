import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, M;

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		N = Integer.parseInt(in.readLine());
		M = Integer.parseInt(in.readLine());

		int DP[] = new int[41];

		DP[0] = 1;
		DP[1] = 1;
		DP[2] = 2;
		DP[3] = 3;

		// 앉을 수 있는 개수
		for (int i = 4; i <= N; i++) {
			DP[i] = DP[i - 1] + DP[i - 2];
		}

		// VIP는 고정이니까 VIP 전까지 진행
		int num;
		int idx = 0;
		int cnt = 1;
		
		boolean flag = true;
		
		for (int i = 0; i < M; i++) {
			num = Integer.parseInt(in.readLine());
			if(num==N)flag = false;
			cnt *= DP[num-idx-1];
			idx = num;
		}
		
		if(flag) {
			cnt *= DP[N-idx];
		}
				
		System.out.println(cnt);
	}
}