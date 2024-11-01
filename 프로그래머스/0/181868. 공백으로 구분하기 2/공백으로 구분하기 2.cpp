#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    string temp = "";
    for(int i=0;i<my_string.size();i++){
        if(my_string[i]==' '){
            if(temp != ""){
                answer.push_back(temp);
            }
            temp = "";
        }
        else{
            temp += my_string[i];
        }
    }
    if(temp != ""){
        answer.push_back(temp);
    }
    return answer;
}