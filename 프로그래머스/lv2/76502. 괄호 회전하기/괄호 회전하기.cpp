#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    //1000^2 이므로 완탐 가능
    //회전 하면서 완전탐색
    for(int i=0;i<s.size();i++){
        //여는 괄호 저장할 스택
        //스택 사용한 이유 : 여는 괄호가 여러번 겹치는 경우 구분
        stack<char>bracket;	
        int flag = 1;	//올바른 괄호 판별
        
        //k=문자열 시작점, j=반복
        for(int k=i,j=0;j<s.size();j++,k++){
            //마지막 인덱스 이후엔 첫 원소로 돌아감
            if(k==s.size())k=0;
            //여는 괄호인 경우 스택에 저장
            if(s[k]=='('||s[k]=='{'||s[k]=='['){
                bracket.push(s[k]);
            }
            //닫는 괄호인 경우
            else{
                //마지막에 열린 괄호와 짝이 아니라면 반복문 종료
                if(s[k]==')' && (bracket.empty() || bracket.top()!='(')){
                    flag = 0;
                    break;
                }
                else if(s[k]=='}'&& (bracket.empty() || bracket.top()!='{')){
                    flag = 0;
                    break;
                }
                else if(s[k]==']'&& (bracket.empty() || bracket.top()!='[')){
                    flag = 0;
                    break;
                }
                //짝이 맞다면 열린 괄호 팝
                bracket.pop();
            }
        }
        //열린 괄호가 남아있지 않고 올바른 문자열인 경우 answer++
        if(bracket.empty() && flag)answer++;
    }
    
    
    
    
    return answer;
}