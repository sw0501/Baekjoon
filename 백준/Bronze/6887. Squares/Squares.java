import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String[] args)throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        double db;
        db = Double.parseDouble(br.readLine());
        
        int ans = (int)(Math.sqrt(db));
        
        System.out.println("The largest square has side length " + ans + ".");
	}
}
