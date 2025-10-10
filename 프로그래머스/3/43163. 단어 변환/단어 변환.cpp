#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int len = begin.size();
    
    int visit[51] = {0,};
        
    queue<pair<string,int>>q;
    
    q.push(make_pair(begin,0));
    
    while(!q.empty()){        
        string str = q.front().first;
        int c =  q.front().second;
        
        if(str == target){
            answer = c;
            break;
        }
        
        q.pop();
        
        for(int i=0;i<words.size();i++){
            if(visit[i])continue;
            
            int cnt = 0;
            
            for(int j=0;j<len;j++){
                if(str[j] == words[i][j]){
                    cnt++;
                }
            }
            
            if(cnt==len-1){
                visit[i] = 1;
                q.push({words[i], c + 1});
            }
        }
        
    }
    
    return answer;
}