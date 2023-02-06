#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int,int>>q;
    
    //위치와 중요도 pair로 큐에 저장
    for(int i=0;i<priorities.size();i++){
        q.push(make_pair(i,priorities[i]));
    }
    
    //중요도 정렬
    sort(priorities.begin(),priorities.end());
    
    int pointer = priorities.size()-1;
    int order = 1;
    
    
    while(!q.empty()){
        pair<int,int>p = q.front();
        q.pop();
        //우선순위가 더 높은 문서가 있는 경우
        if(p.second<priorities[pointer]){
            q.push(p);
        }
       	//우선순위가 더 높은 문서가 없는 경우
        else{
            //요청 문서인 경우
            if(p.first == location){
                return order;
            }
            //아닌 경우 인쇄 순서 증가 && 중요도 이동
            order++;
            pointer--;
        }
    }
        
}