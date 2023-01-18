#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int storey) {
    
    int cnt = 0;
    
    while(storey!=0){
        int tmp = storey%10;
        storey/=10;
        if(tmp==0){
            continue;
        }
        else if(tmp<=5){
            if(tmp==5 && storey%10>=5){
                cnt += 10-tmp;
                storey += 1;
            }
            else cnt += tmp;
            
        }
        else {
            cnt += 10-tmp;
            storey += 1;
        }
    }
    
    cout << cnt << "\n";
    
    return cnt;
}