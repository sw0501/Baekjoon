#include <iostream>

using namespace std;

int main()
{
    // 코드를 작성해주세요
    long long int N;

    while (cin >> N) {
        int num[10] = { 0, };
        int cnt = 10;
        long long int i = 0;
        while(cnt) {
            i++;
            long long int temp = N * i;
            while (temp > 0) {
                if (!num[temp % 10]) {
                    cnt--;
                }
                num[temp % 10]++;
                temp /= 10;
            }
        }
        cout << i << "\n";
    }

    return 0;
}