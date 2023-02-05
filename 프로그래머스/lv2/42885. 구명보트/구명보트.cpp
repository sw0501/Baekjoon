#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    
    sort(people.begin(),people.end());
    
    //투 포인터
    int start = 0;
    int end = people.size()-1;
    int answer = 0;
    
    while(start<=end){
        //동일 인물인 경우 answer++
        if(start==end){
            answer++;
            break;
        }
        
        //2명 태우는 것이 가능한 경우
        if(people[start]+people[end]<=limit){
            answer++;
            start++;
            end--;
        }
        
        //2명 태우는 것이 불가능한 경우 
        //가장 무거운 사람 혼자 탑승 -> 가장 가벼운 사람과 2명 탑승이 불가능하므로
        else{
            answer++;
            end--;
        }
    }
    
    
    return answer;
}