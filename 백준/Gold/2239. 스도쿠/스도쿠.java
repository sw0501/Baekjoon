import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st = null;
	static int map[][] = new int[9][9];
	static List<Cell> empty = new ArrayList<>();

	public static class Cell {
		int x;
		int y;

		Cell(int x, int y) {
			this.x = x;
			this.y = y;
		}

		void print() {
			System.out.println(x + "  " + y);
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		for (int i = 0; i < 9; i++) {
			String str = br.readLine();
			for (int j = 0; j < 9; j++) {
				map[i][j] = (int) (str.charAt(j) - '0');
				if (map[i][j] == 0) {
					empty.add(new Cell(i, j));
				}
			}
		}

		check(0);
		
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				System.out.print(map[i][j]);
			}
			System.out.println();
		}
	}

	private static boolean check(int idx) {
		
		// TODO Auto-generated method stub
		if(idx==empty.size())return true;
		
		int x = empty.get(idx).x;
		int y = empty.get(idx).y;
		
		for(int i=1;i<=9;i++) {
			map[x][y] = i;
			if(checkRow(x,y) && checkCol(x,y) && checkBox(x,y)) {
				if(check(idx+1)) {
					return true;
				}
			}
		}
		
		map[x][y] = 0;
		return false;

	}

	static boolean checkRow(int x, int y) {
		for (int i = 0; i < 9; i++) {
			if(i==x)continue;
			if(map[i][y]==map[x][y]) {
				return false;
			}
		}
		return true;
	}

	static boolean checkCol(int x, int y) {
		for (int j = 0; j < 9; j++) {
			if(j==y)continue;
			if(map[x][j]==map[x][y]) {
				return false;
			}
		}
		return true;
	}

	static boolean checkBox(int x, int y) {
		
		int tx = (x/3) * 3;
		int ty = (y/3) * 3;
		
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(tx+i==x && ty+j==y)continue;
				if(map[tx+i][ty+j]==map[x][y]) {
					return false;
				}
			}
		}
		return true;
	}
}