#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int tmp = n;
    
    while(tmp!=0){
        answer+= tmp%2;
        tmp /= 2;
    }
    
    n++;
    while(1){
        int temp = n;
        int num1 = 0;
        
        while(temp!=0){
            num1 += temp%2;
            temp /= 2;
        }
        if(answer == num1){
            answer = n;
            break;
        }
        n++;
    }
    
    return answer;
}