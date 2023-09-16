#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    
    int l = 0;
    int r = 0;
    for(int i=0;i<str_list.size();i++){
        if(str_list[i] == "l"){
            for(int j=0;j<i;j++){
                answer.push_back(str_list[j]);
            }
            break;
        }
        else if(str_list[i] == "r"){
            for(int j=i+1;j<str_list.size();j++){
                answer.push_back(str_list[j]);
            }
            break;
        }
    }
    return answer;
}