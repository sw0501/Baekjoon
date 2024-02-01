import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	public static StringBuilder sb = new StringBuilder();
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer st;

	static int S, P;
	static String str;
	static int A, C, G, T;
	static int ans = 0;

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		st = new StringTokenizer(br.readLine());
		S = Integer.parseInt(st.nextToken());
		P = Integer.parseInt(st.nextToken());

		str = br.readLine();

		st = new StringTokenizer(br.readLine());
		A = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		G = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());

		int a = 0, c = 0, g = 0, t = 0;

		for (int i = 0; i < P; i++) {
			if (str.charAt(i) == 'A') {
				a++;
			} else if (str.charAt(i) == 'C') {
				c++;
			} else if (str.charAt(i) == 'G') {
				g++;
			} else if (str.charAt(i) == 'T') {
				t++;
			}
		}
		int i = 0, j = P - 1;
		while (true) {
			if (a >= A && c >= C && g >= G && t >= T) {
				ans++;
			}

			j++;
			if (j == S)
				break;

			if (str.charAt(i) == 'A') {
				a--;
			} else if (str.charAt(i) == 'C') {
				c--;
			} else if (str.charAt(i) == 'G') {
				g--;
			} else if (str.charAt(i) == 'T') {
				t--;
			}
			i++;

			if (str.charAt(j) == 'A') {
				a++;
			} else if (str.charAt(j) == 'C') {
				c++;
			} else if (str.charAt(j) == 'G') {
				g++;
			} else if (str.charAt(j) == 'T') {
				t++;
			}
		}

		System.out.println(ans);
	}
}