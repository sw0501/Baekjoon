import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt(); // Input the value of N (the index of the Fibonacci number to find)
        int[] DP = new int[47]; // Array to store Fibonacci numbers, initialized with zeros
        DP[0] = 0; // Base case: Fibonacci number at index 0 is 0
        DP[1] = 1; // Base case: Fibonacci number at index 1 is 1
        
        for (int i = 2; i <= N; i++) {
            DP[i] = DP[i - 1] + DP[i - 2]; // Calculate Fibonacci number at index i using the previous two Fibonacci numbers
        }
        
        System.out.println(DP[N]); // Output the Fibonacci number at index N
    }
}