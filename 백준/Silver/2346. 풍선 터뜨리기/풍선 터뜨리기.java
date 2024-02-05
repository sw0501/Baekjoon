import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static StringBuilder sb = new StringBuilder();

	public static class Node {
		Node preNode;
		int value;
		int num;
		Node nextNode;

		public Node(int value, int num) {
			preNode = null;
			this.value = value;
			this.num = num;
			nextNode = null;
		}

	}

	public static class LinkedList {
		Node head;
		Node node;
		Node tail;
		int index;

		public LinkedList() {
			index = 0;
		}

		public void addList(Node node) {
			if (index == 0) {

				head = node;
				tail = node;

				head.nextNode = tail;
				head.preNode = tail;

				tail.nextNode = head;
				tail.preNode = head;

				this.node = node;

				index++;
			} else {

				node.preNode = tail;
				node.nextNode = head;

				head.preNode = node;
				tail.nextNode = node;

				tail = node;
				index++;
			}
		}

		public int removePre(int idx) {
			if (index == 0) {
				return 0;
			}
			for (int i = 0; i < -idx; i++) {
				node = node.preNode;
			}
			Node preNode = node.preNode;
			Node nextNode = node.nextNode;

			preNode.nextNode = nextNode;
			nextNode.preNode = preNode;

			index--;

			sb.append(node.value).append(" ");
			return node.num;
		}

		public int removeNext(int idx) {
			if (index == 0) {
				return 0;
			}
			for (int i = 0; i < idx; i++) {
				node = node.nextNode;
			}
			Node preNode = node.preNode;
			Node nextNode = node.nextNode;

			preNode.nextNode = nextNode;
			nextNode.preNode = preNode;

			index--;

			sb.append(node.value).append(" ");
			return node.num;
		}

		public boolean isEmpty() {
			if (index == 0)
				return true;
			return false;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		LinkedList list = new LinkedList();

		StringTokenizer st = new StringTokenizer(br.readLine());

		int idx = 1;
		while (st.hasMoreTokens()) {
			list.addList(new Node(idx++, Integer.parseInt(st.nextToken())));
		}

		int num = 0;
		while (!list.isEmpty()) {
			if (num < 0) {
				num = list.removePre(num);
			} else {
				num = list.removeNext(num);
			}
		}

		System.out.println(sb);
	}
}