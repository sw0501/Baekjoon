import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	public static StringBuilder sb = new StringBuilder();
	static int N;

	public static class Food {
		long sour;
		long bitter;
	}

	public static Food[] food;
	public static boolean[] visit;

	public static long diff = -1;

	public static void search(int idx, long sour, long bitter) {

		for (int i = 0; i < N; i++) {
			if(!visit[i]) {
				visit[i] = true;
				long tempDiff = Math.abs(sour * food[i].sour - (food[i].bitter + bitter));
				diff = (diff > tempDiff ? tempDiff : diff);
				search(idx + 1, sour * food[i].sour, food[i].bitter + bitter);
				visit[i] = false;
			}

		}

	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		food = new Food[N];
		visit = new boolean[N];
		
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			food[i] = new Food();
			food[i].sour = Integer.parseInt(st.nextToken());
			food[i].bitter = Integer.parseInt(st.nextToken());
		}

		diff = Long.MAX_VALUE;
		search(0, 1, 0);

		System.out.println(diff);
	}
}