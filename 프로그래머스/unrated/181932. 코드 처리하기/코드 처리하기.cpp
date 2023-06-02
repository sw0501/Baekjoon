#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    
    int mode = 0;
    for(int idx=0;idx<code.size();idx++){
        if(mode==0){
            if(code[idx]=='1'){
                mode = 1;
            }
            else if(idx%2==0){
                answer += code[idx];
            }
        }
        else if(mode==1){
            if(code[idx]=='1'){
                mode = 0;
            }
            else if(idx%2==1){
                answer += code[idx];
            }
        }
    }
    
    if(answer==""){
        answer = "EMPTY";
    }
    return answer;
}