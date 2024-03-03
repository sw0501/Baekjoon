import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static long cnt = 0;
	static int N;
	static long arr[];

	static boolean binarySearch(int left, int right, long target, int self) {
		while (left < right) {

			int mid = (left + right) / 2;

			// 목표 탐색한 경우
			if (mid != self && arr[mid] == target) {
				return true;
			}
			
			if (arr[mid] <= target) {
				left = mid + 1;
			}else {
				right = mid;
			}
		}
		
		if (left != self && arr[left] == target) {
			return true;
		} 

		return false;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		N = Integer.parseInt(in.readLine());
		arr = new long[N];

		st = new StringTokenizer(in.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		//작은 2개의 수는 불가능
		for (int i = 0; i < N; i++) {
			// 이분탐색으로 개수 탐색
			for (int j = 1; j < N; j++) {
				//자기 자신은 수 포함 X
				if(j==i)continue;
				//System.out.println(i + " " + j);
				if(binarySearch(0, j-1, arr[i]-arr[j],i)) {
					//System.out.println(arr[i]);
					cnt++;
					break;
				}
				
			}
		}
		
		System.out.println(cnt);
	}

}