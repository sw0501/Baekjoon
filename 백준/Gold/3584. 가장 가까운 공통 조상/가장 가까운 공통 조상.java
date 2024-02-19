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

	static int T;
	static int N;

	static class Node {
		int depth;
		int value;
		Node parent;
		List<Node> child;

		Node(int value) {
			depth = 0;
			this.value = value;
			parent = null;
			child = new ArrayList<>();
		}

		Node(int value, int depth, Node parent) {
			this.depth = depth;
			this.value = value;
			this.parent = parent;
			child = new ArrayList<>();
		}
	}

	static Node[] nodeList;

	static Node find(int value, Node root) {
		if (root.value == value) {
			return root;
		}
		Node child = null;
		for (int i = 0; i < root.child.size(); i++) {
			root.child.get(i).depth = root.depth + 1;
			child = find(value, root.child.get(i));
			if (child != null)
				break;
		}
		return child;
	}

	public static void main(String[] args) throws IOException {
		T = Integer.parseInt(in.readLine());

		for (int t = 0; t < T; t++) {
			N = Integer.parseInt(in.readLine());
			nodeList = new Node[N + 1];
			int A, B;

			for (int i = 0; i < N - 1; i++) {
				st = new StringTokenizer(in.readLine());
				A = Integer.parseInt(st.nextToken());
				B = Integer.parseInt(st.nextToken());

				// 없는 노드의 경우 생성
				if (nodeList[A] == null) {
					nodeList[A] = new Node(A);
				}
				if (nodeList[B] == null) {
					nodeList[B] = new Node(B);
				}

				nodeList[B].parent = nodeList[A];
				nodeList[A].child.add(nodeList[B]);
			}

			Node root = null;

			// 루트 노드 탐색
			for (int i = 1; i <= N; i++) {
				if (nodeList[i].parent == null) {
					root = nodeList[i];
					break;
				}
			}

			st = new StringTokenizer(in.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());

			Node N1 = find(n1, root);
			Node N2 = find(n2, root);

			// 높이 맞춰주기
			while (N1.depth != N2.depth) {
				if (N1.depth < N2.depth) {
					N2 = N2.parent;
				} else {
					N1 = N1.parent;
				}
			}

			while (N1.value != N2.value) {
				N1 = N1.parent;
				N2 = N2.parent;
			}

			System.out.println(N1.value);
		}
	}
}