#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string,int> name;
    
    for(int i=0;i<completion.size();i++){
        if(name.find(completion[i]) == name.end()){
            name.insert({completion[i],0});
        }
        name[completion[i]]++;
    }
    
    for(int i=0;i<participant.size();i++){
        if(name.find(participant[i]) == name.end()){
            answer = participant[i];
            break;
        }
        else{
            name[participant[i]]--;
            if(name[participant[i]] < 0){
                answer = participant[i];
                break;
            }
        }
    }
        
    return answer;
}