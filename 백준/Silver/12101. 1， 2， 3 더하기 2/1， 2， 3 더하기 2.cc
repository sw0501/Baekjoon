#include <iostream>
#include <algorithm>
#include <vector>
#include<stack>

using namespace std;

int N, K;
int cnt = 0;
stack<int>st;

int check(int num) {
    if (num == 0) {
        cnt++;
        if (cnt == K) {
            return 1;
        }
        else {
            return 0;
        }
    }

    for (int i = 1; i <= 3; i++) {
        if (num - i >= 0) {
            if (check(num - i)) {
                st.push(i);
                return 1;
            }
        }
    }

    return 0;
}

int main()
{    
    cin >> N >> K;

    check(N);

    if (st.empty()) {
        cout << -1 << "\n";
    }
    else {
        while (!st.empty()) {
            cout << st.top();
            st.pop();
            if (!st.empty()) {
                cout << "+";
            }
        }
    }
    

    return 0;
}