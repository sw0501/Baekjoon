#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string,int>match;
    
    for(int i=0;i<players.size();i++){
        match.insert({players[i],i});
        answer.push_back(players[i]);
    }
      
    for(int i=0;i<callings.size();i++){
        int temp = match[callings[i]];
        match[callings[i]] = temp - 1;
        
        //추월당한 선수 
        string temp_str = answer[temp-1];
        match[temp_str] = temp;
        
        temp_str = answer[temp-1];
        answer[temp-1] = callings[i];
        answer[temp] = temp_str;
        
    }
    
    return answer;
}