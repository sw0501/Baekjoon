#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    int max = 0;
    int cnt = 0;
    
    int stric = 1;
    int flag1 = 0;
    int flag2 = 0;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        
        if(flag1){
            flag1 = 0;
            flag2 = 1;
        }
        else if(flag2){
            stric = 1;
            flag2 = 0;
        }
        
        if(num==0){
            if(!stric){
                cnt = 0;
            }
            else{
                stric = 0;
                flag1 = 1;
            }
        }
        else cnt++;
        
        max = (max>cnt?max : cnt);
    }
    
    cout << max << "\n";
    return 0;
}
