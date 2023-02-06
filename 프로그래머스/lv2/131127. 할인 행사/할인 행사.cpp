#include <string>
#include <vector>
#include <iostream>

using namespace std;

int count[11] = {0,};

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    //시작일부터의 물건 개수 카운트
    for(int i=0;i<want.size();i++){
        for(int j=0;j<10;j++){
            if(discount[j]==want[i])count[i]++;
        }
    }
    
   	for(int i=0;i<discount.size();i++){
        int flag = 1;
        //물건 개수 맞는지 체크
        for(int j=0;j<want.size();j++){
            if(count[j]!=number[j]){
                flag = 0;
                break;
            }
        }
        //요청한 수량이 맞는 경우
        if(flag){
            answer++;
        }
        //수량이 맞지 않는 경우
        //물건 없애기
            for(int j=0;j<want.size();j++){
                if(want[j]==discount[i])count[j]--;
            }
            
            if(i+10!=discount.size()){
                //다음 물건 넣기
                for(int j=0;j<want.size();j++){
                    if(want[j]==discount[i+10])count[j]++;
                }
            }
    }
    
    return answer;
}