import java.util.*;
import java.io.*;

class Solution {
    
    static StringTokenizer st;
    
    static int DFS(int [] numbers, int idx, int sum, int target){
        
        int cnt = 0;
        
        if(idx == numbers.length){
            if(sum==target)
                return 1;
            else
                return 0;
        }
        
        cnt += DFS(numbers,idx+1,sum+numbers[idx],target);
        cnt += DFS(numbers,idx+1,sum-numbers[idx],target);
        
        return cnt;
    }
    
    public int solution(int[] numbers, int target) {
        
        int answer = DFS(numbers,0,0,target);
        
        return answer;
    }
}