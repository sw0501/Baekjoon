/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String[] str = br.readLine().split(" ");
		
		int N = Integer.parseInt(str[0]);
		int X = Integer.parseInt(str[1]);
		
		int[] price = new int[N];
		
		String[] p_str = br.readLine().split(" ");
		
		for(int i=0;i<N;i++){
		    price[i] = Integer.parseInt(p_str[i]);
		}
		
		int ans = Integer.MAX_VALUE;
		for(int i=0;i<N-1;i++){
		    if((price[i]+price[i+1])*X<ans){
		        ans = (price[i]+price[i+1])*X;
		    }
		}
		
		bw.write(ans+"\n");
		
		
		br.close();
		bw.close();
	}
}
