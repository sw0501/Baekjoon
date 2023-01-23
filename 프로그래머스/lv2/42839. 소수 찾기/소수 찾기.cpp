#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int>number;
vector<int>decimal;

int flag[7] = {0,};

void BruteForce(int cnt,int num){
    for(int i=0;i<number.size();i++){
        //flag 배열로 방문 여부 표시
        if(flag[i]==0){
            flag[i] = 1;
            
            int temp = num*10 + number[i];
            //소수 체크
            int ck = 0;
            for(int k=2;k<=temp/2;k++){
                if(temp%k==0){
                    ck = 1;
                    break;
                }
            }
            //소수인 경우
            if(!ck && temp >= 2){
                //이미 발견한 소수인지 확인
                auto it = find(decimal.begin(),decimal.end(),temp);
                //처음 발견한 소수인 경우
                if(it == decimal.end()){
					decimal.push_back(temp);
                }
            }
            
            //최대 개수가 아니라면 다음 탐색 진행
            if(cnt != number.size()){
                BruteForce(cnt + 1,temp);
            }
            
            //해당 원소를 분기로 한 탐색 진행 끝나면 flag 원상 복구
            flag[i] = 0;
        }
    }
}

int solution(string numbers) {
    
    //문자열 -> 숫자
    for(char i: numbers){
        number.push_back((int)(i-'0'));
    }
    
    //완전탐색 진행
    BruteForce(1,0);
    
    //발견한 소수 개수 저장
    int answer = decimal.size();
    
    return answer;
}