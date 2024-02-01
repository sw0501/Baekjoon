import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	public static StringBuilder sb = new StringBuilder();

	public static boolean isDecimal(int num) {
		if (num == 1)
			return false;

		for (int i = 2; i <= (int) Math.sqrt(num); i++) {
			if (num % i == 0)
				return false;
		}
		return true;
	}

	public static void recursive(int level, int num) {
		num *= 10;
		for (int i = 1; i < 10; i++) {
			if (isDecimal(num + i)) {
				if (level == 1) {
					sb.append(num + i).append("\n");
				} else {
					recursive(level - 1, num + i);
				}
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		recursive(N, 0);

		System.out.println(sb);
	}
}