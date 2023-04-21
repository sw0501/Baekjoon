#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(pair<string,int>m1, pair<string,int>m2){
    if(m1.first<m2.first){
        return true;
    }
    else return false;
}

int main(){
    
    int N;
    map<string,int>m;
    cin >> N;
    
    for(int i=0;i<N;i++){
        string name;
        string div;
        cin >> name >> div;
        if(div=="enter"){
            m.insert({name,i});
        }
        else {
            m.erase(name);
        }
    }
    
    vector<string>v;

    for(auto iter:m){
        v.push_back(iter.first);
    }
    
    reverse(v.begin(),v.end());
    
    for(auto iter:v){
        cout << iter << "\n";
    }
    
    return 0;
}