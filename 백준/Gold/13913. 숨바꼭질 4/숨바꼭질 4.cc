/*12886*/
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <cmath>
#include <iostream>
#include<stack>

using namespace std;

struct HS{
    int t;
    int p;
};

int visit[300001] = { 0, };

int main() {
    
    int N, K;

    cin >> N >> K;

    queue<HS>q;

    for (int i = 0; i <= 300000; i++) {
        visit[i] = -1;
    }

    q.push({0,N});
    visit[N] = 1;

    int ansT = 0;
    while (!q.empty()) {
        int p = q.front().p;
        int t = q.front().t;

        if (p == K) {
            ansT = t;
            break;
        }
        q.pop();

        if (visit[p + 1]==-1) {
            visit[p + 1] = p;
            q.push({ t + 1,p + 1 });
        }
        if (p-1>=0 && visit[p - 1]==-1) {
            visit[p - 1] = p;
            q.push({ t + 1,p - 1 });
        }
        if (p*2 <= 300000 && visit[p * 2]==-1) {
            visit[p*2] = p;
            q.push({ t + 1,p * 2 });
        }
    }

    int p = K;
    cout << ansT << "\n";

    stack<int>st;
    st.push(p);
    while (p != N) {
        p = visit[p];
        st.push(p);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    

    return 0;
}