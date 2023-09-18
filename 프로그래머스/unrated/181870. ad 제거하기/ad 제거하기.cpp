#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    string pat = "ad";
    
    for(int i=0;i<strArr.size();i++){
        int flag = 0;
        if(strArr[i].length()>=2){
            for(int j=0;j<=strArr[i].length()-pat.length();j++){
                if(strArr[i][j] == 'a' && strArr[i][j+1]=='d')flag = 1;
            }
        }
        if(!flag){
            answer.push_back(strArr[i]);
        }
    }
    
    return answer;
}