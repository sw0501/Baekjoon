#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    
    int idx = -1;
    for(int i=myString.length()-1;i>=pat.length()-1;i--){
        int flag = 1;
        for(int j=pat.length()-1;j>=0;j--){
            if(pat[j] != myString[i-(pat.length()-j-1)])flag = 0;
        }
        if(flag==1){
            idx = i;
            break;
        }
    }
    
    if(idx>=0){
        for(int i=0;i<=idx;i++){
            answer += myString[i];
        }
    }
    return answer;
}