#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int C;
int CK[1000001] = {0,};
vector<string> answer;

//경로 탐색
int DFS(vector<vector<string>> &tickets,int idx, int count){
    //마지막 경로인 경우 1 반환 및 도착지 answer에 저장
    if(count==C){
        answer.push_back(tickets[idx][1]);
        answer.push_back(tickets[idx][0]);
        return 1;
    }
    //방문 체크
    CK[idx]=1;
    //다음 공항 선택
    for(int i=0;i<tickets.size();i++){
        //방문하지 않은 공항인 경우
        if(tickets[i][0]==tickets[idx][1] && CK[i]==0){
            //res로 해당 경로가 올바른지 체크
            int res = DFS(tickets,i,count+1);
            if(res==1){
                //올바르다면 현재 공항 answer에 저장
                answer.push_back(tickets[idx][0]);
                return 1;
            }
        }
    }
    //올바르지 않다면 방문표시 해제
    CK[idx]=0;

    //0 리턴
    return 0;
}

//정렬
bool compare(vector<string>&a, vector<string>&b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]<b[0];
}

vector<string> solution(vector<vector<string>> tickets) {

    //전체 항공권 개수
    C = tickets.size();

    //항공권 정렬
    sort(tickets.begin(),tickets.end(),compare);

    //ICN 공항에서부터 DFS
    for(int i=0;i<tickets.size();i++){
        if(tickets[i][0]=="ICN"){
            CK[i]=1;
            DFS(tickets,i,1);
            CK[i]=0;
        }
    }

    //역순으로 저장된 항공권 정순으로 재정렬
    reverse(answer.begin(),answer.end());

    return answer;
}