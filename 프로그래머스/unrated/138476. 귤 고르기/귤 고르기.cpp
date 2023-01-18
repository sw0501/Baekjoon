#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int,int>&a, pair<int,int>&b){
    //second 기준 내림차순 정렬
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    //같은 크기의 귤 개수 카운트를 위해서 정렬
    sort(tangerine.begin(),tangerine.end());
    
    //귤 크기 개수 저장 벡터 선언
    vector<pair<int,int>>cnt_size;
    
    //tangerine 순회하면서 저장
    int cnt=1;
    for(int i=0;i<tangerine.size();i++){
        //마지막 원소이거나 다음 원소와 크기가 다르다면 size와 cnt 묶어서 cnt_size에 저장
        if(i == tangerine.size()-1||tangerine[i] != tangerine[i+1]){
            cnt_size.push_back(make_pair(tangerine[i],cnt));
            cnt= 1; //초기화
        }
        //크기가 같다면 c++
        else {
            cnt++;
        }
    }
    
    //귤 크기 개수 정렬
    sort(cnt_size.begin(),cnt_size.end(),compare);
    
    //고른 개수 카운트 변수
    int s = 0;
    
    //개수 벡터 순회
    for(int i=0;i<cnt_size.size();i++){
        s+=cnt_size[i].second;  //개수 추가
        answer++;               //종류 추가
        if(s>=k)break;          //종료 조건
    }
    
    return answer;
}