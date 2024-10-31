#include <iostream>

using namespace std;

int main()
{
    // 코드를 작성해주세요
    int N;
    string ans;
    string now;
    cin >> N >> now >> ans;

    string temp = now;

    int answer = 100001;

    //첫 번째 스위치 누르지 않는 경우   
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        //이전 스위치가 다른 경우 누르기
        if (ans[i - 1] != now[i - 1]) {
            cnt++;
            if (now[i] == '0') {
                now[i] = '1';
            }
            else {
                now[i] = '0';
            }
            if (i + 1 < N) {
                if (now[i + 1] == '0') {
                    now[i + 1] = '1';
                }
                else {
                    now[i + 1] = '0';
                }
            }
            
        }
    }
    //불가능한 경우
    if (ans[N - 1] != now[N - 1]) {
        cnt = 100001;
    }

    answer = (answer > cnt ? cnt : answer);

    //첫 번째 스위치 누르는 경우
    now = temp;
    if (now[0] == '0') {
        now[0] = '1';
    }
    else {
        now[0] = '0';
    }
    if (now[1] == '1') {
        now[1] = '0';
    }
    else {
        now[1] = '1';
    }

    cnt = 1;
    for (int i = 1; i < N; i++) {
        //이전 스위치가 다른 경우 누르기
        if (ans[i - 1] != now[i - 1]) {
            cnt++;
            if (now[i] == '0') {
                now[i] = '1';
            }
            else {
                now[i] = '0';
            }
            if (i + 1 < N) {
                if (now[i + 1] == '0') {
                    now[i + 1] = '1';
                }
                else {
                    now[i + 1] = '0';
                }
            }
        }
    }
    //불가능한 경우
    if (ans[N - 1] != now[N - 1]) {
        cnt = 100001;
    }

    answer = (answer > cnt ? cnt : answer);

    if (answer == 100001)answer = -1;

    cout << answer << "\n";
    return 0;
}
