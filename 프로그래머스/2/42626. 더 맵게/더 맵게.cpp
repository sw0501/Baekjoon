#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int>pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(-scoville[i]);
    }
    
    while(!pq.empty() && -pq.top() < K){
        int food1 = -pq.top();
        pq.pop();
        if(pq.empty()){
            answer = -1;
            break;
        }
        int food2 = -pq.top();
        pq.pop();
        
        int newfood = food1 + food2* 2;
        pq.push(-newfood);
        answer++;
    }
    
    return answer;
}