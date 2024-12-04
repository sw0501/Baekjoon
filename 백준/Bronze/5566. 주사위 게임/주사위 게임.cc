#include <iostream>

using namespace std;

int board[1001] = {0,};

int main() 
{
    // 코드를 작성해주세요
    
    int N;
    int M;
    cin >> N;
    cin >> M;
    
    for(int i=1;i<=N;i++){
        cin >> board[i];
    }
    
    int pos = 1;
    int cnt = 0;
    for(int i=0;i<M;i++){
        int num;
        cin >> num;
        
        pos += num;
        cnt++;
        if(pos >= N){
            break;
        }
        pos += board[pos];
        if(pos >= N){
            break;
        }
    }
    cout << cnt << "\n";
    
    return 0;
}
