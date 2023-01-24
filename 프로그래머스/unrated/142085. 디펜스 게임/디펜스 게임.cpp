#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    //무적권 개수가 더 많다면 라운드 개수 반환
    if(k>=enemy.size())answer = enemy.size();
    
    else{
        //무적권 저장용 우선순위 큐
        priority_queue<int,vector<int>,greater<int>>pq;
        int cnt = 0;	//무적권 사용 카운트
        
        for(int i=0;i<enemy.size();i++){
            //무적권을 아직 다 사용하지 않은 경우 저장
            if(cnt<k){
                pq.push(enemy[i]);
                cnt++;
            }
            //다 사용한 경우
            else{
                //기존에 무적권을 사용했던 적보다 더 많은 적이 나타난 경우
                if(pq.top()<enemy[i]){
                    //무적권 사용을 현재 라운드로 변경 후 기존 라운드 병사 소모
                    n-=pq.top();
                    pq.pop();
                    pq.push(enemy[i]);
                }
                //무적권을 사용했던 라운드보다 병사수가 적은 경우 병사 소모
                else n-=enemy[i];
            }
            //병사를 모두 소모한 경우 클리어한 라운드 저장
            if(n<0){
                answer = i;
                break;
            }
        }
        //모든 라운드를 클리어한 경우 라운드 길이 반환
        if(n>=0){
            answer = enemy.size();
        }
    }
    
    return answer;
}