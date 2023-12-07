#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
int A[51] = { 0, };
int B[51] = { 0, };

int main() {
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int cnt = 0;
    while (1) {
        for (int i = 0; i < N; i++) {
            //홀수인 원소가 있는 경우
            if (B[i] % 2 != 0) {
                B[i] -= 1;
                cnt++;
            }
        }
        
        int flag = 1;
        for (int i = 0; i < N; i++) {
            if (B[i] > 0) {
                flag = 0;
            }
            B[i] /= 2;
        }
        //모든 원소가 0이라면
        if (flag) {
            cout << cnt << "\n";
            break;
        }
        else {
            cnt++;
        }
    }

    return 0;
}