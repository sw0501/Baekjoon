#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for(int i=0;i<=myString.length()-pat.length();i++){
        int flag = 1;
        for(int j=0;j<pat.length();j++){
            if(pat[j] != myString[i+j])flag = 0;
        }
        answer += flag;
    }
    
    return answer;
}