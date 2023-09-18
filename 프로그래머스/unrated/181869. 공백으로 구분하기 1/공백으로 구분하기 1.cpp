#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    int s = 0;
    for(int i=0;i<my_string.length();i++){
        if(my_string[i]==' '){
            string temp = "";
            for(int j=s;j<i;j++){
                temp += my_string[j];
            }
            answer.push_back(temp);
            s = i+1;
        }
        else if(i==my_string.length()-1){
            string temp = "";
            for(int j=s;j<=i;j++){
                temp += my_string[j];
            }
            answer.push_back(temp);
        }
    }
    return answer;
}