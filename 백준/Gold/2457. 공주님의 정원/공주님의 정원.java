import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N;

	static int[] month = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	static boolean visit[][];

	static class Project implements Comparable<Project> {
		int startMonth;
		int startDate;
		int endMonth;
		int endDate;

		public Project(int startMonth, int startDate, int endMonth, int endDate) {
			super();
			this.startMonth = startMonth;
			this.startDate = startDate;
			this.endMonth = endMonth;
			this.endDate = endDate;
		}

		@Override
		public int compareTo(Project o) {
			if (startMonth == o.startMonth) {
				return startDate - o.startDate;
			}
			// TODO Auto-generated method stub
			return startMonth - o.startMonth;
		}
		
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		N = Integer.parseInt(in.readLine());

		PriorityQueue<Project> pq = new PriorityQueue<>();

		int sM, sD, eM, eD;

		boolean visit[][] = new boolean[13][32];

		for (int i = 0; i < N; i++) {
			// 무조건 긴 게 좋음
			st = new StringTokenizer(in.readLine());

			sM = Integer.parseInt(st.nextToken());
			sD = Integer.parseInt(st.nextToken());
			eM = Integer.parseInt(st.nextToken());
			eD = Integer.parseInt(st.nextToken());

			if (eM < 3 || (sM >= 12))
				continue;
			
			pq.add(new Project(sM,sD,eM,eD));
		}

		int endMonth = 3;
		int endDate = 1;

		int cnt = 0;

		int tempMonth = -1;
		int tempDate = -1;
		
		// 3월 1일보다 start가 작은 프로젝트 중 가장 긴
		while (!pq.isEmpty()) {
			Project p = pq.poll();
			// 현재 마감일보다 시작일이 빠른 것 중
			if (p.startMonth < endMonth || (p.startMonth == endMonth && p.startDate <= endDate)) {
				// 마감일이 제일 느린 것 선택
				if (p.endMonth > tempMonth || (p.endMonth == tempMonth && p.endDate >= tempDate)) {
					tempMonth = p.endMonth;
					tempDate = p.endDate;
				}
			}
			else {
				//최신화
				cnt++;
				endMonth = tempMonth;
				endDate = tempDate;
				tempMonth = -1;
				tempDate = -1;
				
				if(endMonth >= 12) {
					break;
				}
				
				// 현재 마감일보다 시작일이 빠른 것 중
				if (p.startMonth < endMonth || (p.startMonth == endMonth && p.startDate <= endDate)) {
					// 마감일이 제일 느린 것 선택
					if (p.endMonth > tempMonth || (p.endMonth == tempMonth && p.endDate >= tempDate)) {
						tempMonth = p.endMonth;
						tempDate = p.endDate;
					}
				}
			}
			
			if(endMonth >= 12) {
				break;
			}
		}
		
		if(tempMonth != -1 && tempDate != -1) {
			cnt++;
			endMonth = tempMonth;
			endDate = tempDate;
		}
		
		if(endMonth<=11) {
			cnt = 0;
		}
		
		System.out.println(cnt);
	}

}