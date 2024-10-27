#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{

    vector<string> str;

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        str.push_back(s);
    }

    int h = N-1;

    unordered_set<string> hashset;
    vector<string> substr;
    for (int j = 0; j < M; j++) {
        substr.push_back("");
    }

    for (int i = N-1; i >=0; i--) {
        int flag = 1;
        for (int j = 0; j < M; j++) {
            substr[j] += str[i][j];
            if (hashset.find(substr[j]) == hashset.end()) {
                hashset.insert(substr[j]);
            }
            else {
                flag = 0;
            }
        }
        if (flag) {
            cout << i << "\n";
            break;
        }
        hashset.clear();
    }
    
    

    return 0;
}