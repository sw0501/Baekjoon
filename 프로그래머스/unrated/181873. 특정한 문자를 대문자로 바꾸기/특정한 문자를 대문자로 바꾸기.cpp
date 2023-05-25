#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    for(int i=0;i<my_string.size();i++){
        for(int j=0;j<alp.size();j++){
            if(my_string[i]==alp[j]){
                my_string[i] -= 'a'-'A';
            }
        }
    }
    string answer = my_string;
    return answer;
}