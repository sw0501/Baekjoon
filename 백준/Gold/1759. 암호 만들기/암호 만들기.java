import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static StringBuilder sb = new StringBuilder();
	public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer st;

	static int L, C;

	static List<String> list = new ArrayList<>();

	static boolean check(String str) {

		int cnt1 = -1;
		int cnt2 = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == 'a' || str.charAt(i) == 'e' || str.charAt(i) == 'i' || str.charAt(i) == 'o'
					|| str.charAt(i) == 'u') {
				cnt2++;
			} else {
				cnt1++;
			}
		}

		if (cnt1 > 0 && cnt2 > 0)
			return true;
		return false;
	}

	static void select(int cnt, int idx, String str) {
		if (cnt == L) {
			if(check(str)) {
				System.out.println(str);
			}
		}
		else {
			for (int i = idx; i < C; i++) {
				select(cnt + 1, i + 1, str + list.get(i));
			}
		}
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(in.readLine());

		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(in.readLine());
		for (int i = 0; i < C; i++) {
			list.add(st.nextToken());
		}

		Collections.sort(list);

		select(0, 0, "");
	}
}