import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int ck[] = new int[9];
	static int N;
	static int M;

	public static void recursive(int level, String str, int index) {
		for (int i = index; i <= N; i++) {
			if (ck[i] == 0) {
				ck[i] = 1;
				if (level == M) {
					System.out.println(str + i + " ");
				} else {
					recursive(level + 1, str + i + " ", i + 1);
				}
				ck[i] = 0;
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		recursive(1, "", 1);
	}

}