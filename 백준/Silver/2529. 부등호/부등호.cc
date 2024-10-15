#include <iostream>
#include <climits>
using namespace std;

string M = ""; 
string m = "";
int ans[10] = { 0, };
int num[10] = { 0, };
char comp[10];
int N;

void find(int cnt) {
    if (cnt == N+1) {
        string temp = "";
        for (int i = 0; i <= N; i++) {
            temp += (char)(ans[i] + '0');
        }
        //cout << temp << "\n";

        if (M == "") {
            M = temp;
            m = temp;
        }
        if (M < temp) {
            M = temp;
        }
        if (m > temp) {
            m = temp;
        }

        return;
    }
    for (int i = 0; i < 10; i++) {
        if (num[i])continue;

        if (cnt == 0) {
            ans[cnt] = i;
            num[i] = 1;
            find(cnt + 1);
            num[i] = 0;
        }
        else {
            if (comp[cnt-1] == '<') {
                if (ans[cnt - 1] < i) {
                    ans[cnt] = i;
                    num[i] = 1;
                    find(cnt + 1);
                    num[i] = 0;
                }
            }
            else {
                if (ans[cnt - 1] > i) {
                    ans[cnt] = i;
                    num[i] = 1;
                    find(cnt + 1);
                    num[i] = 0;
                }
            }
        }
        
    }
    return;
}

int main()
{
    // 코드를 작성해주세요
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> comp[i];
    }

    find(0);

    cout << M << "\n" << m << "\n";

    return 0;
}
