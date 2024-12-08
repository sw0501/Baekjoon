#include <iostream>

using namespace std;

int main()
{
    // 코드를 작성해주세요

    
    int T;
    cin >> T;


    for (int t = 0; t < T; t++) {
        string robot[10];

        int N;
        cin >> N;

        int lose[10] = { 0, };

        for (int i = 0; i < N; i++) {
            cin >> robot[i];
        }

        int len = robot[0].size();

        for (int i = 0; i < len; i++) {
            int r = 0;
            int s = 0;
            int p = 0;

            for (int j = 0; j < N; j++) {
                //이미 진 로봇 패스
                if (lose[j])continue;
                if (robot[j][i] == 'R') {
                    r++;
                }
                else if (robot[j][i] == 'S') {
                    s++;
                }
                else {
                    p++;
                }
            }

            //cout << r << " " << s << " " << p << "\n";

            if (r == 0 && s != 0) {
                for (int j = 0; j < N; j++) {
                    if(!lose[j] && robot[j][i] == 'P') {
                        lose[j] = 1;
                    }
                }
            }
            else if (s == 0 && p!=0) {
                for (int j = 0; j < N; j++) {
                    if (!lose[j] && robot[j][i] == 'R') {
                        lose[j] = 1;
                    }
                }
            }
            else if(p==0 && r != 0){
                for (int j = 0; j < N; j++) {
                    if (!lose[j] && robot[j][i] == 'S') {
                        lose[j] = 1;
                    }
                }
            }
        }

        int idx = 0;
        for (int i = 0; i < N; i++) {
            if (!lose[i]) {
                if (!idx) {
                    idx = i + 1;
                }
                else {
                    idx = 0;
                    break;
                }
            }
        }
        cout << idx << "\n";
    }

    return 0;
}