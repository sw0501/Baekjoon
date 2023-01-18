#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int C;

bool compare(vector<int>&a,vector<int>&b){
    if(a[C]==b[C])
        return a[0]>b[0];    //기본키 기준 내림차순 정렬
    return a[C]<b[C];       //col 컬럼 기준 오름차순 정렬
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;

    C = col-1;    //전역변수 저장
    
    //data 정렬
    sort(data.begin(),data.end(),compare);
    
    //S_i 저장 벡터
    vector<int>S;
    
    //S_i 값을 벡터에 저장
    for(int i=row_begin-1;i<=row_end-1;i++){
        int tmp = 0;
        for(int j=0;j<data[i].size();j++){
            tmp += data[i][j]%(i+1);
        }
        S.push_back(tmp);
    }
    
    //S_i XOR 연산
    //0은 XOR 연산 시 무조건 피연산자 값으로 바뀜
    for(int i=0;i<S.size();i++){
        cout << S[i] << " ";
        answer = answer ^ S[i];
    }
    
    //0000
    //1010
    //====
    //1111
    
    return answer;
}