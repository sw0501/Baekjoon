import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
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

	public static int N;

	// 1 ~ 3^N
	public static void divide(int left, int right, String str) {
		// 가장 작은 문제까지 도달한 경우
		if (left == right) {
			sb.append(str);
		} else {
			divide(left, left + (right - left + 1) / 3 - 1, str);
			//중간에 위치한 경우 무조건 공백 출력
			divide(left + (right - left + 1) / 3, left + (right - left + 1) / 3 * 2 - 1, " ");
			divide(left + (right - left + 1) / 3 * 2, right, str);
		}
	}

	public static void main(String[] args) throws IOException {

		String str;
		while ((str = (in.readLine())) != null) {
			N = Integer.parseInt(str);
			divide(1, (int) Math.pow(3, N), "-");
			sb.append("\n");
		}

		System.out.println(sb);
	}
}