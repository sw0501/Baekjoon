#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int cnt = 0;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        
        
        for(int j=0;j<str.length()-1;j++){
            if(str[j] == '0' && str[j+1] == '1'){
                cnt++;
                break;
            }
            else if(str[j]=='O' && str[j+1]=='I'){
                cnt++;
                break;
            }
        }
    }
    
    cout << cnt << "\n";
    
    
    return 0;
}