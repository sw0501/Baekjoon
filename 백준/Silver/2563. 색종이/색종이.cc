

#include <iostream>

using namespace std;

int main()
{
    
    int n;
    int board[101][101] = {0,};
    cin >> n;
    
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                board[x+j][y+k] = 1;
            }
        }
    }
    
    int cnt = 0;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(board[i][j])cnt++;
        }
    }
    
    cout << cnt << "\n";

    return 0;
}
