#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for(int i=0;i<myString.length();i++){
        if(myString[i]>='A' && myString[i]<='Z')myString[i] += 'a'-'A';
    }
    
    for(int i=0;i<pat.length();i++){
        if(pat[i]>='A' && pat[i]<='Z')pat[i] += 'a'-'A';
    }
    
    if(myString.length()<pat.length())return 0;
    
    for(int i=0;i<=myString.length() - pat.length();i++){
        int flag = 1;
        
        for(int j=0;j<pat.length();j++){
            if(myString[j+i] != pat[j])flag = 0;
        }
        
        if(flag==1){
            answer = flag;
        }
    }
    
    return answer;
}