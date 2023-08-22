#include<iostream>

using namespace std;

int main() {

    string str;
    cin >> str;

    int cnt = 0;

    bool ck[26] = { true, };
    for (int j = 0; j < 26; j++) {
        ck[j] = true;
    }

    bool cow[26] = { true, };

    for (int i = 0; i < 52; i++) {
        if (!ck[(int)(str[i] - 'A')])continue;
        for (int j = 0; j < 26; j++) {
            cow[j] = true;
        }
        for (int j = i + 1; j < 52; j++) {
            if (str[j] == str[i])break;
            else {
                cow[(int)(str[j] - 'A')] = !cow[(int)(str[j] - 'A')];
            }
        }
        for (int j = 0; j < 26; j++) {
            if (ck[j] && !cow[j])cnt++;
        }
        ck[(int)(str[i] - 'A')] = false;
    }

    cout << cnt << "\n";

    return 0;
}