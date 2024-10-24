#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string>pre;
    
    bool answer = true;
    
    for(int i=0;i<phone_book.size();i++){
        pre.insert({phone_book[i]});
    }
    
    for(int i=0;i<phone_book.size();i++){
        string temp = "";
        for(int j=0;j<phone_book[i].size();j++){
            temp += phone_book[i][j];
            if(pre.find(temp) != pre.end() && phone_book[i] != temp){
                
                return false;
            }
        }
    }
    return answer;
}