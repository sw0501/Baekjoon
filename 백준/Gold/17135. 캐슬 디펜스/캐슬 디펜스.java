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

	static class Pair {
		int x, y, dist;

		public Pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	static Pair archer[] = new Pair[3];

	static int N, M, D, ans = 0;
	static int field[][];

	static void place() {

		archer[0] = new Pair(N, 0);
		archer[1] = new Pair(N, 0);
		archer[2] = new Pair(N, 0);

		// 궁수 배치
		for (int i = 0; i < M; i++) {
			archer[0].y = i;
			for (int j = i + 1; j < M; j++) {
				archer[1].y = j;
				for (int k = j + 1; k < M; k++) {
					archer[2].y = k;
					fight();
				}
			}
		}
	}

	static int check(Pair enemy, Pair archer) {
		int dist = Math.abs(enemy.x - archer.x) + Math.abs(enemy.y - archer.y);
		return (dist <= D ? dist : 501);
	}

	static void fight() {
		Queue<Pair> queue = new LinkedList<>();
		Queue<Pair> wait = new LinkedList<>();

		// 제거한 병사 수
		int cnt = 0;

		// 앞에 위치한 병사부터 큐에 저장
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i][j] == 1) {
					queue.add(new Pair(i, j));
				}
			}
		}

		// 병사가 저격 당하거나 제외될 때까지 반복
		while (!queue.isEmpty()) {

			Pair target[] = new Pair[3];
			target[0] = new Pair(500, 500);
			target[0].dist = 500;
			target[1] = new Pair(500, 500);
			target[1].dist = 500;
			target[2] = new Pair(500, 500);
			target[2].dist = 500;

			// 궁수가 공격 가능한 경우 탐색
			for (int i = 0; i < 3; i++) {
				while (!queue.isEmpty()) {
					Pair enemy = queue.poll();

					int dist = check(enemy, archer[i]);
					// 공격 범위에 속하는 적이라면 목표에 추가
					if ((target[i].dist > dist) || (target[i].dist == dist && target[i].y > enemy.y)) {
						target[i].x = enemy.x;
						target[i].y = enemy.y;
						target[i].dist = dist;
					}
					wait.add(enemy);
				}
				while (!wait.isEmpty()) {
					queue.add(wait.poll());
				}
			}

			// 공격 및 병사 이동
			while (!queue.isEmpty()) {
				Pair enemy = queue.poll();

				// 공격 여부 검사
				boolean flag = true;

				for (int i = 0; i < 3; i++) {
					if (enemy.x == target[i].x && enemy.y == target[i].y) {
						flag = false;
					}
				}

				// 공격 받지 않았고 범위 내에 있는 경우 대기 장소로 이동
				if (flag) {
					enemy.x++;
					if (enemy.x < N) {
						wait.add(enemy);
					}
				} else {
					cnt++;
				}
			}

			while (!wait.isEmpty()) {
				queue.add(wait.poll());
			}
		}

		ans = Math.max(ans, cnt);
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());

		field = new int[N + 1][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < M; j++) {
				field[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		place();

		System.out.println(ans);
	}
}