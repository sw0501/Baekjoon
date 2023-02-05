#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int ck[100][100] = {0,};
    
    int mx[4] = {1,-1,0,0};
    int my[4] = {0,0,1,-1};
    
    int Mx = maps.size();
    int My = maps[0].length();
    
    //완전 탐색
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            //바다거나 이미 방문한 섬인 경우 건너뜀
            if(maps[i][j]=='X' || ck[i][j] == 1)continue;
            else{
                int food = 0;
                queue<pair<int,int>> island;
                island.push(make_pair(i,j));
                ck[i][j] = 1;
                
                //큐가 빌때까지 주변 땅 계속 탐색
                while(!island.empty()){
                    
                    int x = island.front().first;
                    int y = island.front().second;
                    island.pop();
                    
                    //if(ck[x][y])continue;
                    food += (int)(maps[x][y]-'0');

                    for(int k=0;k<4;k++){
                        //이미 방문한 섬이거나 바다인 경우
                        int tx = x + mx[k];
                        int ty = y + my[k];
                        
                        //범위 벗어나는 경우 제외
                        if(tx<0||tx>=Mx||ty<0||ty>=My)continue;
                        
                        //바다거나 이미 방문한 섬인 경우
                        if(maps[tx][ty]=='X'||ck[tx][ty]==1)continue;
                        else{
                            island.push(make_pair(tx,ty));      
                        	ck[tx][ty] = 1;
                        }
                    }
                    
                }
                answer.push_back(food);
                
            }
        }
    }
    
    
    if(answer.size()==0){
        answer.push_back(-1);
    }
    else sort(answer.begin(),answer.end());
    
    return answer;
}