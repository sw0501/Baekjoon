#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int x,y;    
    
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[i].length();j++){
            if(park[i][j]=='S'){
                x=i;
                y=j;
            }
        }
    }
    
    
    for(int i=0;i<routes.size();i++){
        int move = (int)(routes[i][2]-'0');
        if(routes[i][0]=='N'){
            if(x-move<0)continue;
            
            int flag = 1;
            for(int j=x-move;j<=x;j++){
                if(park[j][y]=='X'){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                x-=move;
            }
        }
        else if(routes[i][0]=='S'){
            if(x+move>=park.size())continue;
            
            int flag = 1;
            for(int j=x;j<=x+move;j++){
                if(park[j][y]=='X'){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                x+=move;
            }
        }
        else if(routes[i][0]=='W'){
            if(y-move<0)continue;
            
            int flag = 1;
            for(int j=y-move;j<=y;j++){
                if(park[x][j]=='X'){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                y-=move;
            }
        }
        else if(routes[i][0]=='E'){
            if(y+move>=park[0].size())continue;
            
            int flag = 1;
            for(int j=y;j<=y+move;j++){
                if(park[x][j]=='X'){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                y+=move;
            }
        }
    }
    
    answer.push_back(x);
    answer.push_back(y);
    

    return answer;
}