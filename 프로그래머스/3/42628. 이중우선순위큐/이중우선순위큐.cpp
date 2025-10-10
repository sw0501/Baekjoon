#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    // 최대힙
    priority_queue<int>bq;
    // 최소힙
    priority_queue<int,vector<int>,greater<int>>sq;
    // 숫자 저장 맵
    unordered_map<int,int> map;
    
    for(int i=0;i<operations.size();i++){
        char op = operations[i][0];
        
        int top = 0;
        
        // 큐 데이터 추가
        if(op == 'I'){
            int num = 0;
            int sign = 1;
            
            for(int j=2;j<operations[i].size();j++){
                if(operations[i][j] == '-'){
                    sign = -1;
                }
                else{
                    num *= 10;
                    num += (int)(operations[i][j]-'0');    
                }
            }
            
            // 부호 설정
            num *= sign;
            
            bq.push(num);
            sq.push(num);
            map[num]++;
        }
        else {
            // 원소가 없는 경우 continue;
            if(map.empty())continue;
            
            // 최댓값 삭제
            if(operations[i][2] == '1'){
                while(!bq.empty() && map[bq.top()] == 0){
                    bq.pop();
                }
                
                if(!bq.empty()){
                    map[bq.top()]--;
                    bq.pop();
                }
            }
            // 최솟값 삭제
            else{
                while(!sq.empty() && map[sq.top()] == 0){
                    sq.pop();
                }
                
                if(!sq.empty()){
                    map[sq.top()]--;
                    sq.pop();
                }
            }
        }
        
        /*
        if(!bq.empty()){
            cout << bq.top() << " ";
        }
        
        if(!sq.empty()){
            cout << sq.top() << " ";
        }
        
        cout << "\n";
        */
    }
    
    while(!bq.empty() && map[bq.top()] == 0){
        bq.pop();
    }
    
    while(!sq.empty() && map[sq.top()] == 0){
        sq.pop();
    }
    
    if(bq.empty() && sq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    
    else{
        answer.push_back(bq.top());
        answer.push_back(sq.top());
    }
    
    
    return answer;
}