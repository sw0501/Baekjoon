#include <string>
#include <set>
#include <bits/stdc++.h>

using namespace std;

int solution(string dirs) {
    
    set<tuple<int,int,int,int>> set;
    
    int answer = 0;
    int x = 5, y= 5;
    
    for(int i=0;i<dirs.size();i++){
        
        int sx = x;
        int sy = y;
        
        if('U'==dirs[i]){
            y++;
            if(y>10){
                y = 10;
                continue;
            }
        }
        else if('D'==dirs[i]){
            y--;
            if(y<0){
                y = 0;
                continue;
            }
        }
        else if('L'==dirs[i]){
            x--;
            if(x<0){
                x = 0;
                continue;
            }
        }
        else if('R'==dirs[i]){
            x++;
            if(x>10){
                x = 10;
                continue;
            }
        }
        
        set.insert({sx, sy, x, y});
        set.insert({x, y, sx, sy});
    }
    
    answer = set.size()/2;
    
    return answer;
}