#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    string t = "000000";
    
    
    int N,K;
    cin >> N >> K;
    
    int cnt = 0;
    int h = 0;
    while(h <= N){
        
        
        for(int i=0;i<6;i++){
            if((int)(t[i]-'0') == K){
                cnt++;
                break;
            }
        }
        
        t[5]++;
        
        if(t[5] > '9'){
            t[5] = '0';
            t[4]++;
        }
        
        if(t[4]=='6'){
            t[4]='0';
            t[3]++;
        }
        
        if(t[3] > '9'){
            t[3]='0';
            t[2]++;
        }
        
        if(t[2]=='6'){
            t[2]='0';
            t[1]++;
        }
        
        if(t[1] > '9'){
            t[1]='0';
            t[0]++;
            
            
        }
        
        h = (int)(t[0] - '0') * 10 + (int)(t[1]-'0');
    }
    
    cout << cnt << "\n";
    return 0;
}
