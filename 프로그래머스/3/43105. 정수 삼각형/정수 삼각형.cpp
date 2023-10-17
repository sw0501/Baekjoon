#include <string>
#include <vector>

using namespace std;

int max(int a,int b){
    if(a>b)return a;
    return b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int len = triangle.size();
    
    //맨 바닥은 신경 쓰지 않음
    for(int i=len-2;i>=0;i--){
        for(int j=0;j<triangle[i].size();j++){
            triangle[i][j] += max(triangle[i+1][j],triangle[i+1][j+1]);
        }
    }
    
    return triangle[0][0];
}