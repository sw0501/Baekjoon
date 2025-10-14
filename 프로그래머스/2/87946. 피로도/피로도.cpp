#include <string>
#include <vector>

using namespace std;

int BruteForce(int k, int t, vector<vector<int>> dungeons, int cnt){
    
    int max = cnt;
    
    for(int i=0;i<dungeons.size();i++){
        if(t&(1 << i))continue;
        
        int minK = dungeons[i][0];
        int useK = dungeons[i][1];
        
        if(minK <= k){
            int temp = BruteForce(k-useK, t|(1<<i), dungeons,cnt+1);
            
            max = (max>temp?max:temp);
        }
    }
    
    return max;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = BruteForce(k,0,dungeons, 0);
    
    return answer;
}