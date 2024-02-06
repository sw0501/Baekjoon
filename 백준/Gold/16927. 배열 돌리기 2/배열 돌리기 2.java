import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static StringBuilder sb = new StringBuilder();

	public static int[][] arr = new int[300][300];
	public static int[][] list = new int[300][1200];
	public static int[] index = new int[300];

	public static int N, M;

	public static void destruct(int level, int w, int h) {
		int idx = 0;
		// 0,0
		for (int i = level; i < h; i++) {
			list[level][idx++] = arr[i][level];
		}
		// N,0
		for (int j = level + 1; j < w; j++) {
			list[level][idx++] = arr[h - 1][j];
		}
		// N,M
		for (int i = h - 2; i >= level; i--) {
			list[level][idx++] = arr[i][w - 1];
		}
		// 0,M
		for (int j = w - 2; j > level; j--) {
			list[level][idx++] = arr[level][j];
		}
	}

	public static void restruct(int level, int w, int h) {
		
		// 0,0
		for (int i = level; i < h; i++) {
			arr[i][level] = list[level][index[level]++];
			index[level] = (index[level] == 2 * (M - 2 * level) + 2 * (N - 2 * level) - 4 ? 0 : index[level]);
		}
		// N,0
		for (int j = level + 1; j < w; j++) {
			arr[h - 1][j] = list[level][index[level]++];
			index[level] = (index[level] == 2 * (M - 2 * level) + 2 * (N - 2 * level) - 4 ? 0 : index[level]);
		}
		// N,M
		for (int i = h - 2; i >= level; i--) {
			arr[i][w - 1] = list[level][index[level]++];
			index[level] = (index[level] == 2 * (M - 2 * level) + 2 * (N - 2 * level) - 4 ? 0 : index[level]);
		}
		// 0,M
		for (int j = w - 2; j > level; j--) {
			arr[level][j] = list[level][index[level]++];
			index[level] = (index[level] == 2 * (M - 2 * level) + 2 * (N - 2 * level) - 4 ? 0 : index[level]);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int w = M;
		int h = N;
		int idx = 0;

		int level = 0;
		while (w >= (M + 1) / 2 && h >= (N + 1) / 2) {
			destruct(idx, w, h);
			idx++;
			w -= 1;
			h -= 1;
			level++;
		}
		level--;

		w = M;
		h = N;
		for (int i = 0; i < level; i++) {
			index[i] = (2 * w + 2 * h - 4) - R % (2 * w + 2 * h - 4);
			index[i] = (index[i] == (2 * w + 2 * h - 4) ? 0 : index[i]);

			w -= 2;
			h -= 2;
		}

		w = M;
		h = N;
		idx = 0;
		while (w >= (M + 1) / 2 && h >= (N + 1) / 2 && idx < level) {
			restruct(idx, w, h);
			idx++;
			w -= 1;
			h -= 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}
}