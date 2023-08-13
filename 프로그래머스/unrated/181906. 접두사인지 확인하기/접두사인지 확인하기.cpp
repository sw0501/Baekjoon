#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 1;
    
    int i=0;
    while(i<my_string.length()&&i<is_prefix.length()){
        if(my_string[i]!=is_prefix[i])answer = 0;
        i++;
    }
    
    if(i<is_prefix.length()){
        answer = 0;
    }
    
    return answer;
}