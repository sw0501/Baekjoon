#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    //체육복 여부
    int clothes[31]={0,};


    //체육복 보유 현황 초기화
    for(int i=1;i<=n;i++){
        clothes[i] = 1;
    }

    //여벌 체육복이 있는 경우 반영
    for(int i:reserve){
        clothes[i]++;
    }

    //도난당한 경우 반영
    for(int i:lost){
        clothes[i]--;
    }

    for(int i=1;i<=n;i++){
        //체육복이 있는 경우 입음
        if(clothes[i]){
            clothes[i]--;
            answer++;
        }
        //체육복이 없는 경우
        else if(clothes[i]==0){
            //앞의 학생이 이미 옷을 입고 여벌 옷이 남은 경우
            if(clothes[i-1]==1){
                clothes[i-1]--;
                answer++;
            }
            //뒤의 학생의 여벌 체육봇이 있는 경우
            else if(clothes[i+1]==2){
                clothes[i+1]--;
                answer++;
            }
        }
    }

    return answer;
}