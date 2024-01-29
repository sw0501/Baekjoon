import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
//		System.setIn(new FileInputStream("Test5.txt"));
		// 여기에 코드를 작성하세요.

		// 8방 탐색 델타
		// 01 상 하
		// 23 좌 우
		// 45 좌상 우하
		// 67 우상 좌하
		int dx[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
		int dy[] = { 0, 0, -1, 1, -1, 1, 1, -1 };

		// 중복 탐색 방지
		boolean ck[][][] = new boolean[20][20][4];

		// 연속 개수
		int cnt[] = new int[2];
		// 오목 위치
		int posX = 20;
		int posY = 20;

		// 입출력
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;

		// 오목판
		char[][] board = new char[20][20];

		// 오목판 입력
		for (int i = 1; i < 20; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j < 20; j++) {
				board[i][j] = st.nextToken().charAt(0);
			}
		}

		// 오목판 탐색
		for (int i = 1; i < 20; i++) {
			for (int j = 1; j < 20; j++) {
				// 0인 경우 무시
				if (board[i][j] == '0')
					continue;
				// 8방 탐색
				for (int k = 0; k < 8; k++) {
					// 이미 체크된 방법은 패스
					if (ck[i][j][k / 2])
						continue;

					// 새로 시작하는 경우 위치 초기화
					if (k % 2 == 0) {
						posX = i;
						posY = j;
					}
					// 연속 개수 초기화
					cnt[k % 2] = 0;
					// 팔방탐색 범위
					int idx = 1;

					while (true) {
						int tx = i + dx[k] * idx;
						int ty = j + dy[k] * idx;
						// 오목알이 범위 내에 있는 경우
						if (tx >= 1 && tx <= 19 && ty >= 1 && ty <= 19) {
							// 같은 오목알인 경우
							if (board[i][j] == board[tx][ty]) {
								// 중복 방지 체크
								ck[i][j][k / 2] = true;
								// 오목알 개수 증가
								cnt[k % 2]++;
								// col이 가장 작은 경우 저장
								// col이 같은 경우엔 row가 가장 작은 경우 저장
								if (ty < posY) {
									posY = ty;
									posX = tx;
								} else if (ty == posY) {
									if (tx < posX) {
										posX = tx;
										posY = ty;
									}
								}
								// 탐색 범위 증가 및 진행
								idx++;
								continue;
							}
						}
						// 다른 색깔이거나 빈 공간이 경우 탐색 종료
						break;
					}
					// 연속된 범위 탐색 종료된 경우
					if (k % 2 == 1) {
						// 5목이 완성된 경우 출력 및 종료
						if (cnt[0] + cnt[1] + 1 == 5) {
							sb.append(board[i][j] + "\n");
							sb.append(posX + " " + posY);
							System.out.println(sb);
							return;
						}
					}
				}
			}
		}
		System.out.println(0);
	}
}