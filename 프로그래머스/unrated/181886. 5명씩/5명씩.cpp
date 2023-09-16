#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names) {
    vector<string> answer;
    
    int i=0;
    while(i<names.size()){
        answer.push_back(names[i]);
        i+=5;
    }
    return answer;
}