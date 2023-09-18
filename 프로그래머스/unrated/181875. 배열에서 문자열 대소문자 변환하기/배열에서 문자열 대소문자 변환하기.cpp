#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for(int i=0;i<strArr.size();i++){
        if(i%2==0){
            for(int j=0;j<strArr[i].length();j++){
                if(strArr[i][j]>='A'&&strArr[i][j]<='Z'){
                    strArr[i][j] += 'a'-'A';
                }
            }
            answer.push_back(strArr[i]);
        }
        else{
            for(int j=0;j<strArr[i].length();j++){
                if(strArr[i][j]>='a'&&strArr[i][j]<='z'){
                    strArr[i][j] -= 'a'-'A';
                }
            }
            answer.push_back(strArr[i]);
        }
    }
    
    return answer;
}