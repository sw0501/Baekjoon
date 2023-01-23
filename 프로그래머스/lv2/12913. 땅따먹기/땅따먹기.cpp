#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//점수 저장용 배열
int DP[100000][4] = {0,};

int solution(vector<vector<int> > land)
{
    int answer = 0;

    //행 탐색
	for(int i=0;i<land.size();i++){
        //열 탐색
        for(int j=0;j<land[i].size();j++){
            DP[i][j] = land[i][j];
            
            //첫 행이 아닌 경우 DP 계산
            //단 j != k 인 경우
            //DP[i][j] = land[i][j] + max(DP[i][k=0,1,2,3]);
           	if(i!=0){
             	//이전 행 탐색
                for(int k=0;k<4;k++){
                    //현재 밟고 있는 열과 동일한 경우 continue
                    if(k==j)continue;
                    //최대값 비교하여 DP에 저장
                    DP[i][j] = max(DP[i][j], land[i][j] + DP[i-1][k]);
                }
                
                //마지막 행인 경우 최대 점수 계산하여 저장
                if(i==land.size()-1){
                    answer = max(answer,DP[i][j]);
                }
                
            }
            
        }
    }
    
    return answer;
}