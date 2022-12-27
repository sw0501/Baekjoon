#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    int x = total / num;
    
    int n = (num-1)/2;
    
    for(int i = x-n; i < x-n+num; i++){
        answer.push_back(i);
    }
    
    
    return answer;
}