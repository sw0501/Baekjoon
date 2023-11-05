#include<iostream>
#include<stack>
#include<utility>
#include<vector>

using namespace std;

int main() {

    int N;
    cin >> N;

    stack<pair<int, int>>r;

    vector<int>s;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        s.push_back(h);
    }

    int idx = 1;
    for(int i=0;i<s.size();i++) {

        int top = s[i];

        while (!r.empty() && r.top().first < top) {
            r.pop();
        }

        if (r.empty()) {
            cout << 0 << " ";
        }
        else {
            cout << r.top().second << " ";
        }
        r.push({ top,idx++ });
    }

    return 0;
}