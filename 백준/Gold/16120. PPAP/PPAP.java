import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static StringBuilder sb = new StringBuilder();
	public static StringTokenizer st;

	public static int N, K;
	public static Stack<Character> stack = new Stack<Character>();

	public static void main(String[] args) throws NumberFormatException, IOException {

		String str = in.readLine();

		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == 'P') {
				stack.add(str.charAt(i));
			} else {
				//마지막에 A 하나 있거나, AA가 남아있거나, 스택에 P가 하나만 있는 경우
				if(i+1 == str.length() || str.charAt(i+1) =='A' || stack.size()<2) {
					System.out.println("NP");
					return;
				}
				else {
					stack.pop();
					stack.pop();
					stack.add(str.charAt(++i));
				}
			}
		}
		
		//System.out.println(stack.size());
		
		if(stack.size()==1) {
			System.out.println("PPAP");
		}
		else {
			System.out.println("NP");
		}
		
		
		//System.out.println(sb);
	}
}
