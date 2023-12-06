#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int block[501][501] = { 0, };
int b[501] = { 0, };

int main() {
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    for (int i = 0; i < W; i++) {
        cin >> b[i];
    }

    int  cnt = 0;
    int h = -1;
    for (int i = 1; i < W-1; i++) {
        int L = 0, R = 0;
        //왼쪽 기준 값 탐색
        for (int j = 0; j < i; j++) {
            L = (L < b[j] ? b[j] : L);
        }
        //오른쪽 기준 값 탐색
        for (int j = i+1; j < W; j++) {
            R = (R < b[j] ? b[j] : R);
        }

        cnt += max(0, min(L, R) - b[i]);
    }

    cout << cnt << "\n";

    return 0;
}