#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

//주최자, 심판
vector<pair<int, int>> o;
vector<pair<int, int>> j;

int score[200001];

int main()
{

    int N, M, K;

    long long int answer = 0;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {

        int a, b;
        cin >> a >> b;

        score[i] = a;

        o.push_back({ a,i });
        j.push_back({ b,i });
    }

    //심판이 고를 사람이면 주최자가 안 고름

    //심판 선택
    sort(j.begin(), j.end());
    reverse(j.begin(), j.end());
    for (int i = 0; i < K; i++) {
        answer += (long long int)score[j[i].second];
        score[j[i].second] = -1;
    }


    //주최자 선택
    sort(o.begin(), o.end());
    reverse(o.begin(), o.end());
    int cnt = 0;
    int i = -1;
    while (cnt < M) {
        i++;
        if (score[o[i].second] < 0)continue;
        answer += (long long int)score[o[i].second];
        cnt++;
    }
    

    cout << answer << "\n";
        

    return 0;
}