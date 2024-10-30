#include <iostream>

using namespace std;

int num[10000001] = { 0, };

int main()
{
    // 코드를 작성해주세요
    int a, b;
    cin >> a >> b;

    num[0] = 1;
    num[1] = 1;
    for (int i = 2; i <= 10000001; i++) {
        if (num[i])continue;
        for (int j = i * 2; j < 10000001; j += i) {
            num[j] = 1;
        }
    }

    int len[9] = { 0, };
    for (int i = a; i <= b; i++) {
        if (i >= 10000000 || num[i])continue;
        else {
            int cnt = 0;
            int temp = i;
            while (temp > 0) {
                len[cnt++] = temp % 10;
                temp /= 10;
            }

            cnt--;
            int s = 0;
            int flag = 1;

            while (s <= cnt) {
                if (len[s++] != len[cnt--]) {
                    flag = 0;
                    break;
                }
            }

            if (flag) {
                cout << i << "\n";
            }
        }
    }

    cout << -1 << "\n";

    return 0;
}