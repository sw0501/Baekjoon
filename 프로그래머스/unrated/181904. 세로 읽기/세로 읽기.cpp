#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    
    int i = c-1;
    while(i<my_string.length()){
        answer += my_string[i];
        i+=m;
    }
    
    return answer;
}