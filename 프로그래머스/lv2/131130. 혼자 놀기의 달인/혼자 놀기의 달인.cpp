#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int cnt [100] = {0,};
    int graph[100] = {0,};
    
    int box = 0;
    for(int i=0;i<cards.size();i++){
        //첫 개봉하는 그룹의 상자인 경우
        if(graph[i]==0){
           	graph[i] = box+1;
            int j = i;
            cnt[box]++;
            //열지 않은 상자일 경우 반복
            while(graph[cards[j]-1]==0){
                graph[cards[j]-1] = box+1;
                cnt[box]++;
                j = cards[j]-1;
            }
            //상자 그룹 번호 증가
            box++;
        }
    }
    
    //역순으로 정렬
    sort(cnt,cnt+100);
    reverse(cnt, cnt+100);
    
    int answer = cnt[0]*cnt[1];
    return answer;
}