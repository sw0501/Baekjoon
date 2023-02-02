#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[1000001] = {0,};

int solution(int x, int y, int n) {
    int answer = 0;
    
    //이미 같은 수 인 경우 횟수 0 리턴
    if(x==y){
        return answer;
    }
        
    //완탐   BFS로도 풀기 가능
    for(int i=x;i<=y;i++){
        //연산 안된 수는 제외
        if(i!=x && arr[i]==0)continue;
        
        //n 더하기
        if(i+n <= y && (arr[i+n] ==0 || arr[i+n] > arr[i] + 1)){
            arr[i+n] = arr[i]+1;
        }
        
        //2 곱하기
        if(i*2 <=y && (arr[i*2] ==0 || arr[i*2] > arr[i] + 1)){
            arr[i*2] = arr[i]+1;
        }
        
        //3 곱하기
        if(i*3 <=y && (arr[i*3] == 0 || arr[i*3] > arr[i] + 1)){
            arr[i*3] = arr[i]+1;
        }
    }
    
    if(arr[y]==0)answer = -1;		//만들기 불가능한 경우 -1
    else answer = arr[y];		//만들기 가능한 경우 횟수 리턴
    
    return answer;
}