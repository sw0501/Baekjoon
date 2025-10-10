#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    int len = skill.length();
    int prev[26] = {0,};
    
    for(int i=0;i<skill_trees.size();i++){
        for(int j=0;j<26;j++){
            prev[j] = 0;
        }
        
        int isPossible = 1;
        for(int j=0;j<skill_trees[i].size();j++){
            for(int k=0;k<len;k++){
                if(skill_trees[i][j] == skill[k]){
                    if(k==0){
                        prev[k] = 1;
                    }
                    else if(prev[k-1]){
                        prev[k] = 1;
                    }
                    else{
                        isPossible = 0;
                        break;
                    }
                }
            }
            if(!isPossible)break;
        }
        answer += isPossible;
    }
    return answer;
}