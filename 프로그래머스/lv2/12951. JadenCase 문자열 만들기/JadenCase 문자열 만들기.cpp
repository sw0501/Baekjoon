#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    int flag = 1;
    //문자열 탐색
    for(int i=0;i<s.length();i++){
        //첫 글자인 경우
        if(flag){
            //소문자인 경우
            if(s[i]>='a' && s[i]<='z'){
                s[i] -= 'a'-'A';
            }
            //다음 첫 글자까지 flag = 0
            if(s[i]!=' ')flag = 0;
        }
        else {
            //공백인 경우
            if(s[i]==' '){
                flag = 1;
            }
            //대문자인 경우
            else if(s[i]>='A' && s[i]<='Z'){
                s[i] += 'a'-'A';
            }
        }
    }
    
    return s;
}