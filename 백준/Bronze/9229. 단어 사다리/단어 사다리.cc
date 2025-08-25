#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
    
    
    
    while(1){
        unordered_set<char> un_set;
        
        string str;
        cin >> str;
        
        if(str == "#")break;
        
        for(int i=0;i<str.length();i++){
            un_set.insert({str[i]});
        }
        
        int flag = str.length();

        while(1){
            cin >> str;
            
            if(str == "#")break;
            if(flag == 0)continue;
            if(str.length() != flag){
                flag = 0;
                continue;
            }
            
            int cnt = 0;
            
            for(int i=0;i<str.length();i++){
                if(un_set.find(str[i]) != un_set.end()){
                    cnt++;
                }
            }
            
            if(cnt != flag-1){
                flag = 0;
            }
            
            un_set.clear();
            
            for(int i=0;i<str.length();i++){
                un_set.insert({str[i]});
            }
        }
        
        if(flag){
            cout << "Correct" << "\n";
        }
        else{
            cout << "Incorrect" << "\n";
        }
    }
    
    
    
    return 0;
}