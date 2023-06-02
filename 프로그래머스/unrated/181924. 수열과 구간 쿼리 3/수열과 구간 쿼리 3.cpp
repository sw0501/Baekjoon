#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer = arr;
    
    for(int i=0;i<queries.size();i++){
        int a = queries[i][0];
        int b = queries[i][1];
        int temp = answer[a];
        answer[a] = answer[b];
        answer[b] = temp;
    }
    return answer;
}