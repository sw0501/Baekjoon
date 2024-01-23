import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	public static int N;
	public static int[][] arr;
	public static int[] minN;
	public static int ans;
	public static List<Integer>list;
	public static List<Integer>tempList;

	public static void bruteForce(int idx, int p, int f, int s, int v, int c) {
		for (int i = idx; i <= N; i++) {
			tempList.add(i);
			// 최소 영양소 만족할 때
			if (p + arr[i][0] >= minN[0] && f + arr[i][1] >= minN[1] && s + arr[i][2] >= minN[2]
					&& v + arr[i][3] >= minN[3]) {
				// 최소 비용일 때
				if (ans > c + arr[i][4]) {
					list.clear();
					for(int num:tempList) {
						list.add(num);
					}
					
					ans = c + arr[i][4];
				}
			}
			bruteForce(i+1,p + arr[i][0], f + arr[i][1], s + arr[i][2], v + arr[i][3], c + arr[i][4]);
			tempList.remove((Integer)i);
		}
	}

	public static void init() throws NumberFormatException, IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());

		ans = Integer.MAX_VALUE;
		list = new ArrayList<>();
		tempList = new ArrayList<>();
		arr = new int[N + 1][5];
		minN = new int[4];

		st = new StringTokenizer(in.readLine());

		for (int i = 0; i < 4; i++) {
			minN[i] = Integer.parseInt(st.nextToken());
		}

		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < 5; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		init();
		bruteForce(1,0, 0, 0, 0, 0);

		if (ans == Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(ans);
			for (int num : list) {
				System.out.print(num + " ");
			}
		}

	}
}
