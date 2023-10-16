#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    int N = citations.size();
    
    sort(citations.begin(),citations.end());
    
    int h = 0;
    for(int i=0;i<N;i++){
        while(h<citations[i]){
            int up = N-i;
            int down = i;
            if(up>=h && down<=h)answer = h;
            h++;
        }
        if(h==citations[i]){
            int up = N-i;
            int down = i;
            if(up>=h && down<=h)answer = h;
            h++;
        }
    }
    
    return answer;
}