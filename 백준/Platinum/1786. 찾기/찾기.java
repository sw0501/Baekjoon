import java.io.*;
import java.util.*;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st = null;

	static int[] getPi(String p) {
		int m = p.length(), j = 0;

		int[] pi = new int[m];

		for (int i = 1; i < m; i++) {
			// 일치하는 접미사를 찾을 때까지 반복
			while (j > 0 && p.charAt(i) != p.charAt(j)) {
				j = pi[j - 1];
			}

			// 일치한다면 돌아갈 지점 선택
			if (p.charAt(i) == p.charAt(j)) {
				pi[i] = ++j;
			}
		}

		return pi;
	}

	public static void main(String[] args) throws IOException {
		String T, P;

		T = br.readLine();
		P = br.readLine();

		List<Integer> list = KMP(T, P, getPi(P));
		
		System.out.println(list.size());
		for(int i:list) {
            sb.append(i+1).append(" ");
		}
        System.out.println(sb);
	}

	private static List<Integer> KMP(String t, String p, int[] pi) {
		// TODO Auto-generated method stub
List<Integer> list = new ArrayList<>();
		int n = t.length(), m = p.length(), j = 0;

		for (int i = 0; i < n; i++) {
			while (j > 0 && t.charAt(i) != p.charAt(j)) {
				j = pi[j - 1];
			}

			if (t.charAt(i) == p.charAt(j)) {
				if (j == m - 1) {
					list.add(i - m + 1);
					j = pi[j];
				} else {
					j++;
				}
			}
		}

		return list;
	}
}