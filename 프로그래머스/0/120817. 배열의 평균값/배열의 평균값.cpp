#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    
    for(auto num:numbers){
        answer  += num;
    }
    
    return answer/numbers.size();
}