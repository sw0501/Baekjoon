import java.util.*;
import java.io.*;

public class Main {
    
    public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static StringTokenizer st;
    
    static int []price = new int[1001];
    static int []DP = new int[1001];
    
    public static void main(String[] args) throws NumberFormatException, IOException{
        // 코드를 작성해주세요
        
        int N = Integer.parseInt(in.readLine());
        
        st = new StringTokenizer(in.readLine());
        
        for(int i=1;i<=N;i++){
            DP[i] = Integer.MAX_VALUE;
            price[i] = Integer.parseInt(st.nextToken());
        }
        
        for(int i=1;i<=N;i++){
            DP[i] = price[i];
            for(int j=1;j<=i;j++){
                DP[i] = Math.min(DP[i],price[j] + DP[i-j]);
            }
        }
        
        System.out.println(DP[N]);
    }
}
