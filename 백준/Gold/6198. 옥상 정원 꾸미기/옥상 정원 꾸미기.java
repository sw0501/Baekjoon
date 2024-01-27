import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

class Building{
	long height;
	long cnt;
	
	public Building(long height, long cnt) {
		this.height = height;
		this.cnt = cnt;
	}
}

public class Main {

	public static int N;
	public static Stack<Building> stack;
	public static long answer;

	public static void init() throws NumberFormatException, IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		N = Integer.parseInt(in.readLine());
		stack = new Stack<Building>();
		answer = 0;
		
		long height = 0;
		
		for (int i = 0; i < N; i++) {
			height = Integer.parseInt(in.readLine());
			while(!stack.isEmpty() && stack.peek().height <= height) {
				Building b = stack.pop();
				answer += b.cnt;
				if(!stack.isEmpty())stack.peek().cnt += b.cnt +1;
			}
			stack.push(new Building(height,0L));
		}
		
		while(!stack.isEmpty()) {
			Building b = stack.pop();
			answer += b.cnt;
			if(!stack.isEmpty())stack.peek().cnt += b.cnt +1;
		}
		
		sb.append(answer);
		
		System.out.println(answer);
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		init();

	}
}
