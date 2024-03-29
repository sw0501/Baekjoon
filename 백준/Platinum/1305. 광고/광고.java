import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int N = Integer.parseInt(br.readLine());
        String p = br.readLine(); // 패턴

        int[] pi = new int[p.length()]; // 부분일치 테이블 배열
        int i = 1; // 본문 포인터
        int j = 0; // 패턴 포인터

        while (i < p.length()) {
            if (p.charAt(i) == p.charAt(j)) {
                i++;
                j++;
                pi[i - 1] = j;
            } else {
                if (j > 0) {
                    j = pi[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        System.out.println(N - pi[i-1]);


    }

}