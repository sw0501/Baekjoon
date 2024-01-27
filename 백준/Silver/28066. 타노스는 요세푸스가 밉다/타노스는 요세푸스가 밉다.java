import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static int N, K;
	public static Queue<Integer>queue;

	public static void init() throws NumberFormatException, IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		queue = new LinkedList<Integer>();
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		for(int i=1;i<=N;i++) {
			queue.add(i);
		}
		
		while(queue.size()>1) {
			queue.add(queue.poll());
			for(int i=1;i<K && queue.size()>1;i++) {
				queue.remove();
			}
		}
		sb.append(queue.poll());
		
		System.out.println(sb);
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		init();

	}
}
