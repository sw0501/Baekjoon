#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    
    for(long long i = begin; i<=end; i++){
        //1인 경우 0 추가
        if(i==1)answer.push_back(0);
        else{
            //아닌 경우 약수 탐색
            int flag = 1;	//소수 판별
            int M = 0;		//가장 큰 약수 <= sqrt(n)
            
            //sqrt(n)까지 탐색 효율성 위해서
            for(int j=2;j<=sqrt(i);j++){
                //약수가 존재한다면
                if(i%j==0){
                    flag = 0;	//판별
                    M=j;		//가장 큰 약수 저장
                    //10,000,000 이하인 약수가 존재한다면 answer 추가
                    if(i/j<=10000000){
                        answer.push_back(i/j);
                        M=0;	//sqrt(n)이하인 약수 삽입 안하기 위해서 0으로 초기화
                        break;
                    }
                }
            }
            //소수라면 1 추가
            if(flag)answer.push_back(1);
            else{
                //10,000,000이하의 약수가 존재하지 않는 경우 가장 큰 약수 추가
                if(M){
                    answer.push_back(M);
                }
            }
        }
    }
    return answer;
}