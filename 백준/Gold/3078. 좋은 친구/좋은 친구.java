
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

	public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static StringBuilder sb = new StringBuilder();
	public static StringTokenizer st;

	public static int N, K;
	public static Student[] student;

	public static class Student {
		int rank;
		String name;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		st = new StringTokenizer(in.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		student = new Student[N];
		for (int i = 0; i < N; i++) {
			student[i] = new Student();
			student[i].rank = i;
			student[i].name = in.readLine();
		}

		Arrays.sort(student, new Comparator<Student>() {

			@Override
			public int compare(Student o1, Student o2) {
				// TODO Auto-generated method stub
				if (o1.name.length() == o2.name.length()) {
					return o1.rank - o2.rank;
				}
				return o1.name.length() - o2.name.length();
			}

		});

//		for (int i = 0; i < N; i++) {
//			System.out.println(student[i].rank + " " + student[i].name);
//		}

		long ans = 0;
		int idx = 0;
		long cnt = 1;
		for (int i = idx + 1; i < N; i++) {
			if (student[i].name.length() > student[idx].name.length()) {
				idx = i;
				cnt = 1;
			} else if (student[i].rank - student[idx].rank <= K) {
//				System.out.print(cnt + "\t");
				ans += cnt++;
//				System.out
//						.println(student[idx].rank + ":" + student[idx].name + student[i].rank + ":" + student[i].name);
			} else {
				while (idx < i && student[i].rank - student[idx].rank > K) {
					idx++;
					cnt--;
				}
				ans += cnt++;
			}
		}

		System.out.println(ans);
	}
}
