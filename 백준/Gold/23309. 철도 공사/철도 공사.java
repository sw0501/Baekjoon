import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
	static	int[] preStation = new int[1000001];
	static	int[] nextStation = new int[1000001];
	static	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static	StringTokenizer st;
	static	StringBuilder sb = new StringBuilder();
    
	public static void main(String[] args) throws NumberFormatException, IOException {
		st = new StringTokenizer(in.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(in.readLine());

		int preStationNumber = -1;
		int curStationNumber = Integer.parseInt(st.nextToken());
		int starStationNumber = curStationNumber;

		while (st.hasMoreTokens()) {
			preStationNumber = curStationNumber;
			curStationNumber = Integer.parseInt(st.nextToken());
			preStation[curStationNumber] = preStationNumber;
			nextStation[preStationNumber] = curStationNumber;
		}

		preStation[starStationNumber] = curStationNumber;
		nextStation[curStationNumber] = starStationNumber;

		String op;
		int i, j;
		for (int m = 0; m < M; m++) {
			st = new StringTokenizer(in.readLine());
			op = st.nextToken();
			if (op.equals("BN")) {
				i = Integer.parseInt(st.nextToken());
				j = Integer.parseInt(st.nextToken());

				sb.append(nextStation[i] + "\n");

				preStation[j] = i;
				nextStation[j] = nextStation[i];

				preStation[nextStation[i]]= j;
				nextStation[i] = j;

			} else if (op.equals("BP")) {
				i = Integer.parseInt(st.nextToken());
				j = Integer.parseInt(st.nextToken());

				sb.append(preStation[i] + "\n");
				preStation[j] = preStation[i];
				nextStation[j] = i;

				nextStation[preStation[i]] = j;
				preStation[i] = j;

			} else if (op.equals("CN")) {
				i = Integer.parseInt(st.nextToken());

				sb.append(nextStation[i] + "\n");
				preStation[nextStation[nextStation[i]]] = i;
				nextStation[i] = nextStation[nextStation[i]];

			} else if (op.equals("CP")) {
				i = Integer.parseInt(st.nextToken());

				sb.append(preStation[i] + "\n");
				nextStation[preStation[preStation[i]]] = i;
				preStation[i] = preStation[preStation[i]];
			}
		}

		System.out.print(sb);

	}
}