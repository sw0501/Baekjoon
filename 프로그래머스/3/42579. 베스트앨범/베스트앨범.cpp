#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct compare{
    bool operator ()(pair<int,int>x, pair<int,int>y){
        if(x.first == y.first){
            return x.second > y.second;
        }
        return x.first < y.first;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string,int> index;
    unordered_map<int,int> count;
    priority_queue<pair<int,int>,vector<pair<int,int>>>genre;
    priority_queue<pair<int,int>,vector<pair<int,int>>, compare>song[10001];
    
    int temp = 0;
    for(int i=0;i<genres.size();i++){
        if(index.find(genres[i]) == index.end()){
            index.insert({genres[i],temp});
            count.insert({temp,plays[i]});
            song[temp].push({plays[i],i});
            temp++;
        }
        else {
            int idx = index[genres[i]];
            count[idx] += plays[i];
            song[idx].push({plays[i],i});
        }
    }
    
    for(auto it : count){
        genre.push({it.second,it.first});
    }
    
    while(!genre.empty()){
        int idx = genre.top().second;
        genre.pop();
        
        int cnt = 0;
        while(!song[idx].empty() && cnt < 2){
            answer.push_back(song[idx].top().second);
            song[idx].pop();
            cnt++;
        }
    }
    
    
    return answer;
}