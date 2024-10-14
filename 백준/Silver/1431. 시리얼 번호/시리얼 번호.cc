#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string &s1, string &s2){
    if(s1.size() == s2.size()){
        int len = s1.size();
        
        int a=0,b=0;
        for(int i=0;i<len;i++){
            if(s1[i]>='0' && s1[i]<='9'){
                a += (int)(s1[i]-'0');
            }
            if(s2[i]>='0' && s2[i]<='9'){
                b += (int)(s2[i]-'0');
            }
        }
        
        if(a==b){
            return s1<s2;
        }
        return a<b;
    }
    
    return s1.size() < s2.size();
}

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    vector<string>str;
    
    string s;
    
    for(int i=0;i<N;i++){
        cin >> s;
        str.push_back(s);
    }
    
    sort(str.begin(),str.end(),compare);
    
    for(int i=0;i<N;i++){
        cout << str[i] << "\n";
    }
    
    return 0;
}
