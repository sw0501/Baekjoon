#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<pair<int,int>>arrive;
    priority_queue<pair<int,int>>jobList;
    
    for(int i=0;i<jobs.size();i++){
        arrive.push({-jobs[i][0], i});
    }
    
    //마지막 작업 처리 시간
    int last = 0;
    
    while(1){
        
        //현재 시간까지 요청된 작업들 대키 큐에 저장
        while(!arrive.empty() && last >= -arrive.top().first){
            int num = arrive.top().second;
            arrive.pop();
            jobList.push({-jobs[num][1],jobs[num][0]});
        }
        
        //현재 대기중인 작업이 없는 경우
        if(jobList.empty()){
            int num = arrive.top().second;
            arrive.pop();
            
            answer += jobs[num][1];
            //현재 시간을 작업 마무리 시간으로 변경
            last = jobs[num][0] + jobs[num][1];
        }
        else{
            int start = jobList.top().second;
            int process = -jobList.top().first;
            jobList.pop();

            last += process;
            answer += last - start;
        }
        
        if(arrive.empty() && jobList.empty())break;
    }
    
    return (int)(answer / jobs.size());
}