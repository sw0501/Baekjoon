#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    unordered_set<string> set;
    
    set.insert({"ChongChong"});
    
    int cnt = 1;
    
    for(int i=0;i<N;i++){
        string str1, str2;
        
        cin >> str1 >> str2;
        
        if(set.find(str1) != set.end() || set.find(str2) != set.end()){
           
            if(set.find(str1) == set.end()){
                set.insert({str1});    
                cnt++;
            }
            if(set.find(str2) == set.end()){
                set.insert({str2});    
                cnt++;
            }
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
}