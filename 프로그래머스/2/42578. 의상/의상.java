import java.util.*;

class Solution {
    static Map<String,Integer> hashmap = new HashMap<>();
    static StringTokenizer st;
    public int solution(String[][] clothes) {
        int answer = 1;
        
        for(int i=0;i<clothes.length;i++){
            String clothe = clothes[i][0];
            String category = clothes[i][1];
            
            hashmap.putIfAbsent(category,0);
            hashmap.replace(category, hashmap.get(category)+1);
        }
        
        for(int value : hashmap.values()){
            answer *= value+1;
        }
        
        return answer - 1;
    }
}