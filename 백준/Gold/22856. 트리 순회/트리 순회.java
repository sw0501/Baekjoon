import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static StringBuilder sb = new StringBuilder();
	public static int[][] child = new int[100001][2];

	public static class Node {
		int value;
		Node leftNode;
		Node rightNode;

		Node(int value) {
			this.value = value;
			leftNode = null;
			rightNode = null;
		}

		public Node getLeftNode() {
			return leftNode;
		}

		public void setLeftNode(Node leftNode) {
			this.leftNode = leftNode;
		}

		public Node getRightNode() {
			return rightNode;
		}

		public void setRightNode(Node rightNode) {
			this.rightNode = rightNode;
		}
	}

	public static class Tree {
		Node root;

		Tree() {
			root = new Node(1);
		}
	}

	public static int ans = -1; // 루트 들어가는 경우 제외

	public static void preOrder(Node root, boolean isLeft) {
		if (root.leftNode != null) {
			preOrder(root.leftNode, true);
		}
		
		if (isLeft) {
			ans += 2;
		} else {
			ans += 1;
		}
		if (root.rightNode != null) {
			preOrder(root.rightNode, isLeft);
		}
	}

	public static void makeTree(Node root) {
		if (child[root.value][0] != -1) {
			root.setLeftNode(new Node(child[root.value][0]));
			makeTree(root.leftNode);
		}
		if (child[root.value][1] != -1) {
			root.setRightNode(new Node(child[root.value][1]));
			makeTree(root.rightNode);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(in.readLine());

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			int root = Integer.parseInt(st.nextToken());
			int left = Integer.parseInt(st.nextToken());
			int right = Integer.parseInt(st.nextToken());
			child[root][0] = left;
			child[root][1] = right;
		}

		Tree tree = new Tree();

		makeTree(tree.root);
		preOrder(tree.root,false);

		System.out.println(ans);

	}
}