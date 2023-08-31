#include<iostream>
#include<map>

using namespace std;

string arr[48];
int ck[48] = { 0, };

int N;
int cnt = 0;

int comp(string a, string b) {
    int dist = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i])dist++;
    }
    return dist;
}

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;
        cnt = 0;

        for (int i = 0; i < N; i++) {
            string str;
            cin >> str;

            if (i < 48) {
                arr[i] = str;
            }
        }
        int min_dist = 10000000;
        for (int i = 0; i < (N > 48 ? 48 : N); i++) {
            for (int j = i + 1; j < (N > 48 ? 48 : N); j++) {
                for (int k = j + 1; k < (N > 48 ? 48 : N); k++) {

                    int dist = comp(arr[i], arr[j]) + comp(arr[i], arr[k]) + comp(arr[j], arr[k]);

                    if (min_dist > dist)min_dist = dist;
                }
            }
        }

        cout << min_dist << "\n";

    }


    return 0;
}