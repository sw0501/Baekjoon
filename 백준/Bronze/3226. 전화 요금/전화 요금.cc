#include <iostream>

using namespace std;

int main()
{
    // 코드를 작성해주세요
    int T;
    cin >> T;

    int answer = 0;

    for (int t = 0; t < T; t++) {
        int h = 0, m = 0;
        int d = 0;
        string str;
        cin >> str;

        h *= 10;
        h += (int)(str[0] - '0');
        h *= 10;
        h += (int)(str[1] - '0');

        m *= 10;
        m += (int)(str[3] - '0');
        m *= 10;
        m += (int)(str[4] - '0');

        cin >> str;
        d *= 10;
        d += (int)(str[0] - '0');
        d *= 10;
        d += (int)(str[1] - '0');


        //60
        //75
        //150
        //150
        //통화 요금 1분에 5원
        if (h < 7) {
            int minute = m + d;
            if (h == 6 && minute >= 60) {
                answer += (minute - 60) * 10;
                answer += (d - (minute - 60)) * 5;
                
            }
            else {
                answer += d* 5;
            }
        }
        else if (h < 19) {
            int minute = m + d;
            if (h == 18 && minute >= 60) {
                answer += (minute - 60) * 5;
                answer += (d-(minute - 60)) * 10;
            }
            else {
                answer += d* 10;
            }
        }
        else {
            answer += d * 5;
        }    
    }
    
    cout << answer << "\n";
    return 0;
}
