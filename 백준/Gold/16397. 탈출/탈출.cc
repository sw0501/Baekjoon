#include <iostream>
#include <queue>

using namespace std;

int visit[100000] = { 0, };

int main()
{
    queue<pair<int, int>> q;

    int N, T, G;
    cin >> N >> T >> G;
    
    q.push({ N,T });

    int cnt = -1;

    visit[N] = T;

    while (!q.empty()) {
        int num = q.front().first;
        int t = q.front().second;
        q.pop();
        //cout << num << " " << t << "\n";
        if (G == num) {
            cnt = T - t;
            break;
        }

        if (t == 0)continue;

        int A = num + 1;
        int B = num*2;

        if (B <= 99999) {
            int remain = 1;
            while (remain <= B) {
                remain *= 10;
            }
            remain /= 10;

            B -= remain;
        }
        
        //cout << A << " " << B << "\n\n";
        if (A <= 99999 && !visit[A]) {
            visit[A] = 1;
            q.push({ A,t - 1 });
        }
        if (num != 0 && B <= 99999 && !visit[B]) {
            visit[B] = 1;
            q.push({ B,t - 1 });
        }
    }

    if (cnt == -1) {
        cout << "ANG" << "\n";
    }
    else {
        cout << cnt << "\n";
    }

    return 0;
}