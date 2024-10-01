#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int t = 1;
    int maxHealth = health;
    for(int i=0;i<attacks.size();i++){
        int attackTime = attacks[i][0];
        int damage = attacks[i][1];
        
        //이전 시간까지 체력 회복
        int period = attackTime - t;
        
        int heal = period*bandage[1] + period/bandage[0]*bandage[2];
        
        health = min(maxHealth, health + heal);
        
        //공격
        health -= damage;
        
        t = attackTime + 1;
        
        if(health <= 0)return -1;
    }
    
    return health;
}