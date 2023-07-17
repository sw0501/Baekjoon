#include<iostream>

using namespace std;

int main(){
    
    int N;
    string str;
    
    cin >> N >> str;
    
    int cnt = 0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            cnt++;
        }
    }
    cout << cnt << "\n";
    
    return 0;
}