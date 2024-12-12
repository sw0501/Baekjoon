#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    int N;
    cin >> N;
    
    long long int sx,sy,ex,ey;
    cin >> sx >> sy >> ex >> ey;
    
    int idx = -1;
    long long int total = -1;
    for(int i=0;i<N;i++){
        int M;
        cin >> M;
        
        long long int temp = 0;
        
        long long int tx = sx;
        long long int ty = sy;
        
        for(int j=0;j<M;j++){
            long long int a,b;
            cin >> a >> b;
            
            temp += abs(a - tx) + abs(b - ty);
            tx = a;
            ty = b;
        }
        
        temp += abs(tx - ex) + abs(ty - ey);
        
        if(total == -1){
            total = temp;
            idx = i;
        }
        else{
            if(total >= temp){
                total = temp;
                idx = i;
            }
        }
    }
    
    cout << idx + 1 << "\n";
    return 0;
    
}
