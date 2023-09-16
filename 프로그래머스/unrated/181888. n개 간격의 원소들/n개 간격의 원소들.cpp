#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    int i=0;
    while(i<num_list.size()){
        answer.push_back(num_list[i]);
        i+=n;
    }
    return answer;
}