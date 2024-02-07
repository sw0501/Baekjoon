import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
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

	public static int[][] arr;
	public static int N, M, R;

	public static void reverseUpDown() {
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M; j++) {
				int temp = arr[i][j];
				arr[i][j] = arr[N - i - 1][j];
				arr[N - i - 1][j] = temp;
			}
		}
	}

	public static void reverseLeftRight() {
		for (int j = 0; j < M / 2; j++) {
			for (int i = 0; i < N; i++) {
				int temp = arr[i][j];
				arr[i][j] = arr[i][M - j - 1];
				arr[i][M - j - 1] = temp;
			}
		}
	}

	public static void rotateRight() {

		int[][] temp = new int[Math.max(N, M)][Math.max(N, M)];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[j][N - i - 1] = arr[i][j];
			}
		}

		int swap = M;
		M = N;
		N = swap;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = temp[i][j];
			}
		}
	}

	public static void rotateLeft() {
		int[][] temp = new int[Math.max(N, M)][Math.max(N, M)];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[M - j - 1][i] = arr[i][j];
			}
		}

		int swap = M;
		M = N;
		N = swap;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = temp[i][j];
			}
		}

	}

	public static void rotateSubRight() {
		int[][] temp = new int[N / 2][M / 2];

		// part1 임시 저장
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M / 2; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		// part 4 -> part 1
		for (int i = N / 2; i < N; i++) {
			for (int j = 0; j < M / 2; j++) {
				arr[i - N / 2][j] = arr[i][j];
			}
		}

		// part 3 -> part 4
		for (int i = N / 2; i < N; i++) {
			for (int j = M / 2; j < M; j++) {
				arr[i][j - M / 2] = arr[i][j];
			}
		}

		// part 2 -> part 3
		for (int i = 0; i < N / 2; i++) {
			for (int j = M / 2; j < M; j++) {
				arr[i + N / 2][j] = arr[i][j];
			}
		}

		// part 1 -> part 2
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M / 2; j++) {
				arr[i][j + M / 2] = temp[i][j];
			}
		}
	}

	public static void rotateSubLeft() {
		int[][] temp = new int[N / 2][M / 2];

		// part1 임시 저장
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M / 2; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		// part 2 -> part 1
		for (int i = 0; i < N / 2; i++) {
			for (int j = M / 2; j < M; j++) {
				arr[i][j - M / 2] = arr[i][j];
			}
		}

		// part 3 -> part 2
		for (int i = N / 2; i < N; i++) {
			for (int j = M / 2; j < M; j++) {
				arr[i - N / 2][j] = arr[i][j];
			}
		}

		// part 4 -> part 3
		for (int i = N / 2; i < N; i++) {
			for (int j = 0; j < M / 2; j++) {
				arr[i][j + M / 2] = arr[i][j];
			}
		}

		// part 1 -> part 4
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M / 2; j++) {
				arr[i + N / 2][j] = temp[i][j];
			}
		}
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(in.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());

		// 회전 고려
		arr = new int[Math.max(N, M)][Math.max(N, M)];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		st = new StringTokenizer(in.readLine());

		for (int r = 0; r < R; r++) {
			int op = Integer.parseInt(st.nextToken());
			switch (op) {
			case 1:
				reverseUpDown();
				break;
			case 2:
				reverseLeftRight();
				break;
			case 3:
				rotateRight();
				break;
			case 4:
				rotateLeft();
				break;
			case 5:
				rotateSubRight();
				break;
			case 6:
				rotateSubLeft();
				break;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}
}