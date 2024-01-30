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
		int[] sw = new int[N + 1];

		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			sw[i] = Integer.parseInt(st.nextToken());
		}

		int M = Integer.parseInt(br.readLine());

		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());

			if (s == 1) {
				for (int j = 1; j <= N; j++) {
					if(j%num==0)
						sw[j] ^= 1;
				}
			}
			else {
				int l, r;
				l = r = num;
				sw[num] ^= 1;
				l--;
				r++;
				while(l>0 && r<=N) {
					if(sw[l] == sw[r]) {
						sw[l--] ^= 1;
						sw[r++] ^= 1;
					}
					else {
						break;
					}
				}
			}
		}
		for(int i=1;i<=N;i++) {
			System.out.print(sw[i] + " ");
			if(i%20==0)System.out.println();
		}
	}

}