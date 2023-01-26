using namespace std;

#include<iostream>
#include<algorithm>

long long solution(int w,int h) {
    w = (long long)w;
    h = (long long)h;
    long long answer = 1;

    answer = (long long)w*(long long)h-(w+h);
    
    int lost = 0;
    
    int c = 0;
    while(h!=0){
        c = w%h;
        w = h;
        h = c;
    }
    
    lost = w;
    
    answer += w;
    
    return answer;
}