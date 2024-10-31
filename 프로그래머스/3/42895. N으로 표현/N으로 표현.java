import java.util.*;

class Solution {
    static List<HashSet<Integer>>list = new ArrayList<>();
    
    public int solution(int N, int number) {
        
        int temp = 0;
        list.add(new HashSet<Integer>());
        
        for(int i=1;i<=8;i++){
            list.add(new HashSet<Integer>());
            temp *= 10;
            temp += N;
            
            if(temp == number){
                return i;
            }
            
            list.get(i).add(temp);
        }
        
        for(int i=2;i<=8;i++){
            for(int j=1;j<i;j++){
                int k = i-j;
                for(int n1 : list.get(j)){
                    for(int n2 : list.get(k)){
                        list.get(i).add(n1 + n2);
                        list.get(i).add(n1 - n2);
                        list.get(i).add(n1 * n2);
                        if(n2 != 0)list.get(i).add(n1 / n2);
                    }
                }
                
                if(list.get(i).contains(number)){
                    return i;
                }
            }
        }
        
        return -1;
    }
}