import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st = null;

	static int N;

	//접두사 접미사
	static int[] getPI(String p) {
		int m = p.length(), j = 0;

		int[] pi = new int[m];

		for (int i = 1; i < m; i++) {
			//돌아갈 위치가 있고 서로 다른 경우
			while (j > 0 && p.charAt(i) != p.charAt(j)) {
				j = pi[j - 1];
			}
			//접두사와 접미사가 일치하는 경우
			if (p.charAt(i) == p.charAt(j)) {
				//실패시 돌아갈 위치 지정
				pi[i] = ++j;
			}
		}

		return pi;
	}

	//KMP 함수
	static List<Integer> KMP(String s, String p) {
		//정답 리스트
		List<Integer> ans = new ArrayList<>();
		//접두사 접미사 일치 개수
		int[] pi = getPI(p);

		int n = s.length(), m = p.length(), j = 0;

		for (int i = 0; i < n; i++) {
			//일치하지 않는 경우
			while (j > 0 && s.charAt(i) != p.charAt(j)) {
				//실패 위치로 돌아
				j = pi[j - 1];
			}
			//일치하는 경우
			if (s.charAt(i) == p.charAt(j)) {
				//마지막까지 전부 일치하는 경우
				if (j == m - 1) {
					//ans에 추가
					ans.add(i - m + 1);
					//돌아갈 위치
					j = pi[j];
				} else {
					//j 개수 증가
					j++;
				}
			}
		}
		return ans;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		//문자열 입력
		String s = br.readLine();
		String p = br.readLine();

		//KMP 실행
		List<Integer> ans = KMP(s, p);

		System.out.println(ans.size());
		for (int i : ans) {
			System.out.print(i + 1 + " ");
		}

	}

}