import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static StringBuilder sb = new StringBuilder();
	public static StringTokenizer st;
	static int N, K;
	static int alpabet = 0;
	static int words[] = new int[50];

	static int ans = 0;

	static void recursive(int idx) {

		if(K==0) {
			check();
			return;
		}
		for (int i = idx; i < 26; i++) {
			// 비트 만들기
			int c = (0 << i);
			c += 1;
			c = c << (25-i);
			//System.out.println("alpabet");
			//System.out.println(Integer.toBinaryString(c));
			//System.out.println(Integer.toBinaryString(alpabet));
			if ((alpabet & c) == 0) {
				int preBit = alpabet;
				alpabet |= c;
				
				K--;
				check();
				
				if (K > 0) {
					recursive(i + 1);
				}
				
				K++;
				alpabet = preBit;
				
			}
		}
	}

	static void check() {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			//System.out.println(Integer.toBinaryString(words[i]));
			//System.out.println(Integer.toBinaryString(alpabet));
			//System.out.println();
			if ((words[i] & alpabet) == words[i]) {
				cnt++;
			}
		}
		ans = (ans > cnt ? ans : cnt);
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		st = new StringTokenizer(in.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		K -= 5;

		// a c i n t
		for (int i = 0; i < 26; i++) {
			if (i == (int) ('a' - 'a') || i == (int) ('c' - 'a') || i == (int) ('i' - 'a') || i == (int) ('n' - 'a')
					|| i == (int) ('t' - 'a')) {
				alpabet += 1;
			}
			if (i != 25)
				alpabet = alpabet << 1;
		}

		String word;
		for (int i = 0; i < N; i++) {
			word = in.readLine();
			boolean arr[] = new boolean[26];
			for (int j = 0; j < word.length(); j++) {
				arr[(int) (word.charAt(j) - 'a')] = true;
			}
			for (int j = 0; j < 26; j++) {
				if (arr[j])
					words[i] += 1;
				if (j != 25)
					words[i] = words[i] << 1;
			}
		}

		if (K < 0) {
			sb.append(0);
		} else {
			recursive(0);
			sb.append(ans);
		}

		System.out.println(sb);
	}
}
