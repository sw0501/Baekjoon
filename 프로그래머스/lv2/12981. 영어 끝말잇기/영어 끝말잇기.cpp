#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> word;
    int cnt[100001] = {0,};
    int N = 1;
    
    char c=words[0][0];
    for(int i=0;i<words.size();i++){
        if(N>n)N = 1;
        cnt[N]++;
        if(words[i].length()==1 || find(word.begin(),word.end(),words[i]) != word.end() || c!=words[i][0]){
            answer.push_back(N);
            answer.push_back(cnt[N]);
            break;
        }
        word.push_back(words[i]);
        c = words[i][words[i].length()-1];
        N++;
    }
    
    if(answer.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}