#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int t_avg = (int)(floor(N * 0.15 + 0.5));

    if (N == 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> v;

    int m, M;
    m = t_avg;
    M = N - t_avg;

    //cout << m << " " << M << "\n";

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());


    //cout << m << " " << M << "\n";

    int sum = 0;
    for (int i = m; i < M; i++) {
        sum += v[i];
    }

    double avg = (double)sum / (N - t_avg * 2);

    int i_avg = (int)(floor(avg + 0.5));

    cout << i_avg << "\n";


    return 0;
}