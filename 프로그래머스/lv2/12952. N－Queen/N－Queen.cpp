#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int answer = 0;
int N;
int row[13] = {0,};

bool check(int r){
    for(int i=0;i<r;i++){
        //열에 이미 퀸이 있는 경우
        if(row[i]==row[r])return false;
        
        //대각선에 퀸이 있는 경우
        else if(abs(row[i] - row[r]) == r - i)return false;
    }
    return true;
    
}

void BackTracking(int I,int cnt){
    for(int i=I;i<N;i++){
        for(int j = 0;j<N;j++){
            row[i] = j;
            //대각선 상 기울기 비교
            if(check(i)){
                if(cnt==N)answer++;
                else BackTracking(i+1,cnt+1);
            }
            row[i] = 0;
        }
    }
    
}

int solution(int n) {
    N = n;
    BackTracking(0,1);
    
    return answer;
}