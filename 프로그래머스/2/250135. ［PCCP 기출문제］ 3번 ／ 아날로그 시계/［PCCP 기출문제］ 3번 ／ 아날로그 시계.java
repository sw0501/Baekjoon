class Solution {
    public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
        int answer = 0;
        
        int s = h1 * 3600 + m1 * 60 + s1;
        int e = h2 * 3600 + m2 * 60 + s2;
        
        //시침 : 43200 -> 1/120 0.00083 
        //분침 : 3600 -> 0.1
        //초침 : 60 -> 6
        //시침 초침 겹쳐있는지?
        
        //0시 0분 0초 기준 계산 시작
        int ts = h2 * 3600 + m2 * 60 + s2;
        
        int m = 0;
        //분침 계산
        m += 
            h2 * 59
            + (m2- 1)
            + (m2 * 60 * 0.1 + s2 * 0.1 <= s2 * 6 ? 1 : 0);
        System.out.println(m);
        
        m -= 
            h1 * 59
            + (m1 - 1)
            + (m1 * 60 * 0.1 + s1 * 0.1 < s1 * 6 ? 1 : 0);
        
        System.out.println(m);
        
        int h = 0;
        //시침 계산
        h += 
            (h2) * 60 - (h2>=12?1:0)
            + (m2- 1)
            + ((h2 * 30) % 360 + (double)(m2 * 60 + s2) / 120 <= (double)s2 * 6 ? 1 : 0);
        
        //660
        System.out.println(h);
        
        h -= 
            (h1) * 60 - (h1>=12?1:0)
            + (m1 - 1)
            + ((h1 * 30) % 360 + (double)(m1 * 60 + s1) / 120 < (double)s1 * 6 ? 1 : 0);
        //720 - 1
        //659 + 58 + (330 + (59 * 60 + 30) / 120 < 59 * 6
        //359.75 < 354
        System.out.println(h);
        
        //시침 분침 초침 모두 겹칠 때
        if(s == 0)m--;
        if(s <= 43200 && 43200 <= e)m--;
        
        
        return m + h;
    }
}